#ifndef SERVEROBJECT_H
#define SERVEROBJECT_H

namespace lae3
{
    namespace server
    {
        class ServerObject
        {
            public:
                explicit ServerObject();
                virtual ~ServerObject();

                virtual void update(const float dt);

            protected:

            private:
        };
    }
}


#endif // SERVEROBJECT_H
