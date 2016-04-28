#ifndef _OPTIONS_H_
#define _OPTIONS_H_

#include <stdint.h>

// Holds options that can be supplied via commandline.
struct Options {
  Options() : listen_addr("127.0.0.1"),
              listen_port(5053),
              logfile("/dev/stdout"),
              logfd(-1),
              daemonize(false),
              user("nobody"),
              group("nobody"),
              uid(-1), gid(-1),
              bootstrap_dns("8.8.8.8,8.8.4.4") { }
  ~Options();

  const char *listen_addr;
  uint16_t listen_port;

  // Logfile.
  const char *logfile;
  int logfd;

  // Whether to fork into background.
  bool daemonize;

  // User/group to drop permissions to if root.
  // Not used if running as non-root.
  const char *user;
  const char *group;

  // Derived from the above.
  uid_t uid;
  gid_t gid;

  // DNS servers to look up dns.google.com
  const char *bootstrap_dns;

  bool ParseArgs(int argc, char **argv);
  void ShowUsage(int argc, char **argv);
};

#endif  // _OPTIONS_H_