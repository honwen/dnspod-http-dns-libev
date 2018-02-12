# dnspod-http-dns-libev

Modify from https://github.com/aarond10/https_dns_proxy

To adopt to https://www.dnspod.cn/httpdns/guide

Features:

* Tiny Size (<35kiB).
* Uses curl for HTTP/2 and pipelining, keeping resolve latencies extremely low.
* Single-threaded, non-blocking select() server for use on resource-starved 
  embedded systems.
* Designed to sit in front of dnsmasq or similar caching resolver for
  transparent use.

## BUILD

Depends on `c-ares`, `libcurl`, `libev`.

On Debian-derived systems those are libc-ares-dev,
libcurl4-{openssl,nss,gnutls}-dev and libev-dev respectively.  
On Redhat-derived systems those are c-ares-devel, libcurl-devel and
libev-devel.

```bash
$ cmake . && make -j
```

## INSTALL

There is no installer at this stage - just run it.

```
# ./http-dns -u nobody -g nogroup -d
```

## Usage

Just run it as a daemon and point traffic at it. Commandline flags are:

```
Usage: ./http-dns [-a <listen_addr>] [-p <listen_port>]
        [-e <subnet>] [-d] [-u <user>] [-g <group>] [-l <logfile>]
  -a listen_addr    Local address to bind to. (0.0.0.0)
  -p listen_port    Local port to bind to. (5353)
  -e subnet_addr    An edns-client-subnet to use such as "203.31.0.0/16". ()
  -d                Daemonize.
  -u user           User to drop to launched as root. (nobody)
  -g group          Group to drop to launched as root. (nobody)
  -t proxy_server   Optional HTTP proxy. e.g. socks5://127.0.0.1:1080
                    Remote name resolution will be used if the protocol
                    supports it (http, https, socks4a, socks5h), otherwise
                    initial DNS resolution will still be done via the
                    bootstrap DNS servers.
  -l logfile        Path to file to log to. (-)
  -x                Use HTTP/1.1 instead of HTTP/2. Useful with broken
                    or limited builds of libcurl (false).
  -v                Increase logging verbosity. (INFO)
  -h                Show Usage and Exit.
```

## TODO

* Test coverage could be better.

## AUTHORS

* Aaron Drew (aarond10@gmail.com)
* chenhw2 (https://github.com/chenhw2)
