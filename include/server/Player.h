#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include <server/ServerObject.h>

namespace lae3
{
    namespace server
    {
        class Player : public ServerObject
        {
            public:
                explicit Player(std::string name, unsigned short port = 0);
                virtual ~Player();

                void setName(const std::string &name);
                void setPort(const unsigned short port);

                std::string getName() const;
                unsigned short getPort() const;

            protected:

            private:
                std::string m_name;
                unsigned short m_port;
        };
    }
}

#endif // PLAYER_H
