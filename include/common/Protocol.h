#ifndef PROTOCOL_H
#define PROTOCOL_H

namespace lae3
{
    namespace common
    {
        class Protocol
        {
            public:
                static bool registerPlayer(const std::string &name, unsigned short &port);
            protected:
            private:
        };
    }
}

#endif // PROTOCOL_H
