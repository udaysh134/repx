#include "repx.hpp"

int main() {
    RepX repx;

    // repx.credential.authenticate.forStandard();
    
    Context::Ledger::Project_Create{
        ._01_project_name = "",
        ._02_project_description = "",
        ._03_owner_name = ""
    };

    repx.project.create(Context::Ledger::Project_Create{
        ._01_project_name = "",
        ._02_project_description = "",
        ._03_owner_name = ""
    });

    repx.credential.create(LedgerContext::Credential_Create{});
    repx.credential.create(StandardContext::Credential_Create{
        ._01_password = ""
    });

    repx.credential.authenticate(LedgerContext::Credential_Authenticate{
        ._01_public_key = "",
        ._02_private_key = ""
    });

    repx.credential.authenticate(StandardContext::Credential_Authenticate{
        ._01_password = "",
        ._02_salt = "",
        ._03_hash = ""
    });
}