#include <sys/types.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "logging.h"
#include "json_to_dns.h"
#include "text_to_dns.h"

#define MAX_MSG_LENGTH 512

const unsigned char* template = "{\"Status\": 0,\"TC\": false,\"RD\": true,\"RA\": true,\"AD\": false,\"CD\": false,\"Question\":[ {\"name\": \"%s.\",\"type\": 1}],\"Answer\":[ {\"name\": \"%s.\",\"type\": 1,\"TTL\": 99,\"data\": \"%s\"}]}";

int text_to_dns(uint16_t tx_id, char *in, uint8_t *out, int olen) {
  // DLOG(in);
  char* findPos = strstr(in, ":");
  if (findPos < 0 || strlen(in) <= (findPos - in)) return -1;
  else {
    char buf[MAX_MSG_LENGTH] = "";

    findPos[0] = '\0';
    char *name = in;
    char *data = findPos + 1; // findPos + strlen(":");
    snprintf(buf, sizeof(buf) - 1, template, name, name, data);
    DLOG(buf);
    return json_to_dns(tx_id, buf, out, olen);
  }
}
