#pragma once
#include <dlfcn.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <iostream>

class AltVMT {
public:
    AltVMT(void *instance)
    {
        this->instance = (void ***) instance;
        this->size = estvmtsize(*this->instance);
        this->real = *this->instance;
        this->fake = new void *[this->size];
        memcpy(this->fake, this->real, sizeof(**this->instance) * this->size);
        *this->instance = this->fake;
    }

    ~AltVMT()
    {
        *this->instance = this->real;
        delete[] this->fake;
    }

    void ***instance;
    size_t size;
    void **real;
    void **fake;
    
private:
    size_t estvmtsize(void **vmt) const
    {
        size_t x = 0;
        while (vmt[x] != NULL) {
            x++;
        }
        return x;
    }
};

/*AltVMT vmt(vgui);
vmt->fake[21] = my_something;
((something_t) vmt->real[21])(...);*/
