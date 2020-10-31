//
// Created by Pavel Bibichenko on 30.10.2020.
//

#ifndef EGLE_APPLICATIONCONTEXT_H
#define EGLE_APPLICATIONCONTEXT_H

namespace eGLEBites
{
    class Root;

    class ApplicationContext {
    public:
        void root();
        Root *getRoot();

    protected:
        void setup();
        void addInputListener(ApplicationContext *context);

    private:

    };
}

#endif //EGLE_APPLICATIONCONTEXT_H
