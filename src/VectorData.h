
#ifndef MDLEX_VECTORDATA_H
#define MDLEX_VECTORDATA_H

namespace nsgraph
{
/*
    VectorData is a simple contiguous (eventually aligned) way of storing high dimensional vectors
*/
class VectorData {
    private:
        std::vector<float> data; // aligned data
    public:
        VectorData(const size_t dimensions, const size_t num_vectors);
        ~VectorData();
        uint32_t storeVector(std::vector<float>& vec);

        // void deleteVector(uint32_t id);
};



} // nsgraph

#endif //MDLEX_VECTORDATA_H