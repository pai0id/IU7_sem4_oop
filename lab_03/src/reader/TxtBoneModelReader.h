#pragma once
#include "BoneModelReader.h"
#include <fstream>
#include <memory>

class TxtBoneModelReader : public BoneModelReader {
    public:
        TxtBoneModelReader(std::string filename);
        virtual ~TxtBoneModelReader();


        virtual void Open();
        virtual void Close();
        virtual bool IsOpen();

        virtual std::vector<Point> ReadPoints();
        virtual std::vector<Edge> ReadEdges();

    protected:
        std::string _fname;
        std::ifstream _file;
};
