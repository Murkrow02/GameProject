#pragma once
#include "dialog.hpp"


class shop : public dialog {

    protected:


    public:

        shop();

        //Wait for current dialog close
        std::future<void> wait_close;

};