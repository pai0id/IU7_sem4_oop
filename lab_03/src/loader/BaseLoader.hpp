/**
 * Project Untitled
 */


#ifndef _BASELOADER_H
#define _BASELOADER_H

class BaseLoader {
public:
    BaseLoader() = default;

    virtual void Open() = 0;
    virtual void Close() = 0;
    virtual bool IsOpen() = 0;
};

#endif //_BASELOADER_H
