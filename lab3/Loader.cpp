#include "Loader.h"
#include <fstream>

using namespace std;

Loader::Loader(const std::string& path) : m_path(path)
{
    isLoad();
}

Loader::~Loader()
{
}

std::vector<glm::vec2> Loader::vertices() const
{
    return m_vertices;
}

std::vector<int> Loader::indices() const
{
    return m_indices;
}

bool Loader::isLoad()
{
    ifstream inputFile(m_path);
    if (!inputFile.is_open()) {
        return false;
    }

    char elementType;
    while (inputFile >> elementType) {
        if (elementType == 'v') {
            float x, y;
            inputFile >> x >> y;
            m_vertices.emplace_back(x, y);
        }
        else if (elementType == 'f') {
            int index;
            while (inputFile.peek() != '\n' && inputFile >> index) {
                m_indices.push_back(index);
            }
        }
    }

    return true;
}
