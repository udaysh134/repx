#pragma once

#include <string>


class Ledger {
    public:
        class Credential {
            private:
                struct Context {
                    std::string public_key;
                    std::string private_key;
                };
            
            
            public:
                struct Create {
                    Context forLedger();
                };
            
                struct Authenticate {
                    bool forLedger(std::string public_key, std::string private_key);
                };
        };
};