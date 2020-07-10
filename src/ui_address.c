#include "os.h"
#include "os_io_seproxyhal.h"

#include "algo_ui.h"
#include "algo_keys.h"
#include "algo_addr.h"

void
step_address()
{
  char checksummed[65];
  uint8_t publicKey[32];
  cx_ecfp_private_key_t privateKey;

  algorand_key_derive(0, &privateKey);
  algorand_public_key(&privateKey, publicKey);
  checksummed_addr(publicKey, checksummed);
  ui_text_put(checksummed);
}
