#pragma once
#include  "BoneModelReader.h"
#include <sqlite3.h>
#include <memory>

class SqliteBoneModelReader : public BoneModelReader {
    public:
        SqliteBoneModelReader(std::string filename);
        virtual ~SqliteBoneModelReader();


        virtual void Open();
        virtual void Close();
        virtual bool IsOpen();

        virtual std::vector<Point> ReadPoints();
        virtual std::vector<Edge> ReadEdges();

    protected:
        std::string _fname;
        sqlite3 * _db;
};
