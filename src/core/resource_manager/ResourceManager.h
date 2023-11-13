#ifndef ENGINE_RESOURCEMANAGER_H
#define ENGINE_RESOURCEMANAGER_H

#include <string>
#include <unordered_map>

template <typename Resource>
class ResourceManager {
public:
    ResourceManager(const std::string& folder, const std::string& extension) : folder("assets/" + folder + "/"), extension("." + extension) {}

    const Resource& get(const std::string & name) {
        if (!exists(name)) {
            add(name);
        }

        return resources.at(name);
    }

    bool exists(const std::string& name) {
        return resources.find(name) != resources.end();
    }

    void add(const std::string& name) {
        Resource resource;
        if (!resource.loadFromFile(getFullFilename(name))) {
            Resource fail;
            fail.loadFromFile(getFullFilename(folder + "fail" + extension));
            resources.insert(std::make_pair(name, fail));
        } else {
            resources.insert(std::make_pair(name, resource));
        }
    }

private:
    std::string getFullFilename(const std::string& filename) {
        return folder + filename + extension;
    }

    const std::string folder;
    const std::string extension;

    std::unordered_map<std::string, Resource> resources;
};

#endif //ENGINE_RESOURCEMANAGER_H
