#include "vectordata.h"

namespace nsgraph
{
    VectorData::VectorData(size_t dimensions, size_t num_vectors) {
            data.reserve(dimensions * num_vectors);
    }

    uint32_t VectorData::storeVector(std::vector<float>& vec) {
        data.assign(vec.begin(), vec.end());
    }
} // nsgraph