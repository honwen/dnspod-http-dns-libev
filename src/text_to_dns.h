// A simple TEXT -> DNS packet converter.
#ifndef _TEXT_TO_DNS_H_
#define _TEXT_TO_DNS_H_

#ifdef __cplusplus
extern "C" {
#endif
// Creates a DNS packet from a TEXT Format: [Domain]:[IP].
// 'tx_id' is the ID to use in the packet, 'in' is the JSON representation.
// 'out' is a buffer to write the packet to. 'olen' is buffer length in bytes.
// Returns size of packet on success, -1 on failure.
int text_to_dns(uint16_t tx_id, char *in, uint8_t *out, int olen);
#ifdef __cplusplus
}
#endif

#endif // _TEXT_TO_DNS_H_
