#
# Automatically generated make config: don't edit
#

#
# SnapGear Apps/Libs
#
CONFIG_LIB_LIBPAM=y
# CONFIG_USER_CGI_ETH1_BRIDGE is not set
# CONFIG_USER_CGI_NO_SERIAL is not set
CONFIG_USER_CGI_NO_COM2=y
# CONFIG_USER_CGI_NO_DIALIN is not set
CONFIG_USER_CGI_HELP=y
CONFIG_USER_CGI_DMZ=y
CONFIG_USER_CGI_GUEST=y
CONFIG_USER_CGI_FAILOVER=y
CONFIG_USER_CGI_LOAD_BALANCING=y
CONFIG_USER_CGI_HIGHAVAIL=y
CONFIG_USER_CGI_VLAN=y
# CONFIG_USER_CGI_BRIDGE is not set
# CONFIG_USER_CGI_LOOPBACK is not set
# CONFIG_USER_CGI_CUSTOM_HTML is not set
# CONFIG_USER_CGI_FIXED_PRIMARY_MEDIA is not set
# CONFIG_USER_CGI_NO_AUTO_DUPLEX is not set
# CONFIG_USER_CGI_NO_100BASET4 is not set
CONFIG_USER_CGI_ETH_GENERIC=y
CONFIG_USER_CGI_WIZARD=y
# CONFIG_USER_CGI_WIZARD_NO_WAN is not set
# CONFIG_USER_CGI_HTTPS_ONLY is not set
# CONFIG_USER_CGI_NO_SUPPORT_REPORT is not set
# CONFIG_USER_CGI_NO_FW_RULES is not set
# CONFIG_USER_CGI_NO_EDIT_CONFIG is not set
# CONFIG_USER_CGI_ROOT_ONLY is not set
# CONFIG_USER_CGI_NO_TZO_AD is not set
# CONFIG_USER_CGI_SGC_SET_KEY is not set
CONFIG_USER_CGI_MAX_IPSEC_TUNNELS=0
# CONFIG_USER_CGI_RECOVERY is not set
CONFIG_USER_FIREWALL_TOOLS=y
# CONFIG_USER_FIREWALL_BRIDGE_LAN is not set
# CONFIG_USER_FIREWALL_DEFAULT_FLOOD_DISABLE is not set
# CONFIG_USER_FIREWALL_SCRIPT_ONLY is not set
CONFIG_SIZE_CONNTRACK=32768
CONFIG_SIZE_RT_CACHE=131072
# CONFIG_USER_AES_PERF is not set
CONFIG_USER_BR_BR=y
# CONFIG_USER_CERBERIAN_CERBERIAN is not set
# CONFIG_USER_CERBERIAN_PROXYAUTH is not set
# CONFIG_USER_CERBERIAN_CERBTEST is not set
# CONFIG_USER_DESTEST_DESTEST is not set
# CONFIG_USER_DESTEST_DESPERF is not set
# CONFIG_USER_EMCTEST_EMCECHO is not set
# CONFIG_USER_EMCTEST_EMCTEST is not set
# CONFIG_USER_FACTORY_FACTTEST is not set
# CONFIG_USER_GDSD_GDSD_INET is not set
CONFIG_USER_GRE_GRE=y
CONFIG_USER_IDB_IDB=y
# CONFIG_USER_IPSEC_CONFIGURATOR is not set
CONFIG_USER_REDIALER_REDIALER=y
# CONFIG_USER_PKTDELAY_PKTDELAY is not set
# CONFIG_USER_PROTECT is not set
# CONFIG_USER_SETKEY_SETKEY is not set
# CONFIG_USER_IOD is not set
CONFIG_USER_SWTEST_SWCONFIG=y
CONFIG_USER_SWTEST_SWTEST=y
CONFIG_USER_SWTEST_SWITCH_NUM=1
# CONFIG_USER_SWTEST_RTL8305SB is not set
CONFIG_USER_SWTEST_RTL8305SC=y
# CONFIG_USER_SWTEST_RTL8309SB is not set
CONFIG_USER_MGMT_MGMT=y
CONFIG_USER_SGSNMPD_AGENT=y
CONFIG_USER_SGSNMPD_SNAPGEAR=y
CONFIG_USER_SGSNMPD_AGENT=y
CONFIG_USER_SGSNMPD_UDP=y
# CONFIG_USER_SGSNMPD_TCP is not set
CONFIG_USER_SGSNMPD_SNAPGEAR=y
# CONFIG_USER_SGSNMPD_SERVGATE is not set
# CONFIG_USER_TQRECV_TQRECV is not set
# CONFIG_USER_UPNPD is not set
# CONFIG_USER_WINSD_WS is not set
CONFIG_LIB_STLPORT=y
CONFIG_LIB_ZLIB=y
# CONFIG_USER_OPENSSL_APPS is not set
CONFIG_LIB_EXPAT=y
CONFIG_LIB_TINYTCL=y
CONFIG_USER_CGI_PRIMARY_ETHERNET=0

#
# SnapGear Device Settings
#
CONFIG_SIZE_VAR_PART=1024
CONFIG_SIZE_CONFIG_PART=1024
CONFIG_SIZE_SYSLOG_MAXSIZE=64

#
# Core Applications
#
CONFIG_USER_INIT_INIT=y
CONFIG_USER_INIT_CONSOLE_SH=y
CONFIG_USER_INIT_RUN_FIREWALL=y
# CONFIG_USER_INIT_CONF is not set
# CONFIG_USER_SASH_SH is not set
# CONFIG_USER_SH_SH is not set
# CONFIG_USER_NWSH_SH is not set
CONFIG_USER_BASH_BASH=y
# CONFIG_USER_MSH_SH is not set
# CONFIG_USER_OTHER_SH is not set
# CONFIG_USER_SASH_REBOOT is not set
# CONFIG_USER_SASH_REBOOT_SNAPGEAR is not set
# CONFIG_USER_SASH_SHUTDOWN is not set
# CONFIG_USER_INIT_EXPAND is not set
# CONFIG_USER_VERSION_VERSION is not set
# CONFIG_USER_LOGIN_LOGIN is not set
# CONFIG_USER_OLD_PASSWORDS is not set
# CONFIG_USER_ONLY_ROOT is not set
# CONFIG_USER_AGETTY_AGETTY is not set
CONFIG_USER_GETTYD_GETTYD=y
# CONFIG_USER_MGETTY_MGETTY is not set
# CONFIG_USER_LOGIN_PASSWD is not set
CONFIG_USER_CRON_CRON=y

#
# Real Time Clock
#
CONFIG_USER_HWCLOCK_HWCLOCK=y
# CONFIG_USER_RTC_M41T11 is not set
# CONFIG_USER_RTC_DS1302 is not set

#
# Vixie-cron
#
# CONFIG_USER_VIXIECRON_CRON is not set
# CONFIG_USER_VIXIECRON_CRONTAB is not set

#
# at
#
# CONFIG_USER_AT_AT is not set
# CONFIG_USER_AT_ATD is not set
# CONFIG_USER_AT_ATRUN is not set

#
# Library Configuration
#

#
# Force build (Normally built when required)
#
# CONFIG_LIB_FLEX_FORCE is not set
# CONFIG_LIB_LIBAES_FORCE is not set
# CONFIG_LIB_LIBDES_FORCE is not set
# CONFIG_LIB_LIBSSL_FORCE is not set
# CONFIG_LIB_LIBGMP_FORCE is not set
# CONFIG_LIB_LIBG_FORCE is not set
# CONFIG_LIB_LIBLDAP_FORCE is not set
# CONFIG_LIB_LIBLZMA_FORCE is not set
# CONFIG_LIB_LIBLZO_FORCE is not set
# CONFIG_LIB_LIBNET_FORCE is not set
# CONFIG_LIB_LIBPAM_FORCE is not set
# CONFIG_USER_PAM_LDAP is not set
CONFIG_USER_PAM_SMB=y
CONFIG_USER_PAM_TACACS=y
# CONFIG_LIB_LIBPCAP_FORCE is not set
# CONFIG_LIB_LIBPCRE_FORCE is not set
# CONFIG_LIB_ZLIB_FORCE is not set
# CONFIG_LIB_LIBBZ2_FORCE is not set
# CONFIG_LIB_LIBATM_FORCE is not set
# CONFIG_LIB_LIBPNG_FORCE is not set
# CONFIG_LIB_LIBJPEG_FORCE is not set
# CONFIG_LIB_LIBUPNP_FORCE is not set
# CONFIG_LIB_NCURSES_FORCE is not set
# CONFIG_LIB_LIBEFENCE_FORCE is not set
CONFIG_LIB_STLPORT=y
# CONFIG_LIB_STLPORT_SHARED is not set
# CONFIG_LIB_EXPAT_FORCE is not set
# CONFIG_LIB_ADNS_FORCE is not set
# CONFIG_LIB_ARES_FORCE is not set
# CONFIG_LIB_LIBIDN_FORCE is not set
# CONFIG_LIB_LIBCURL_FORCE is not set
# CONFIG_LIB_LIBCRYPT_OLD_FORCE is not set

#
# Library Configuration
#
# CONFIG_LIB_UC_LIBC_TIMEZONE is not set

#
# Flash Tools
#
CONFIG_USER_FLASHW_FLASHW=y
CONFIG_USER_NETFLASH_NETFLASH=y
CONFIG_USER_FLASH_FLASH=y
CONFIG_USER_NETFLASH_WITH_FTP=y
CONFIG_USER_NETFLASH_WITH_CGI=y
CONFIG_USER_NETFLASH_VERSION=y
# CONFIG_USER_NETFLASH_VERSION_ALLOW_CURRENT is not set
# CONFIG_USER_NETFLASH_VERSION_ALLOW_OLDER is not set
CONFIG_USER_NETFLASH_DECOMPRESS=y
CONFIG_LIB_ZLIB=y
# CONFIG_USER_NETFLASH_AUTODECOMPRESS is not set
# CONFIG_USER_NETFLASH_HMACMD5 is not set
# CONFIG_USER_RECOVER_BIOS is not set
# CONFIG_USER_NETFLASH_CRYPTO is not set
# CONFIG_USER_RECOVER_STATIC_TFTP is not set
# CONFIG_USER_RECOVER_RECOVER is not set
CONFIG_USER_SETMAC_SETMAC=y

#
# uCbootloader utils
#
# CONFIG_USER_BOOTTOOLS_LOADER is not set
# CONFIG_USER_BOOTTOOLS_HIMEMLOADER is not set
# CONFIG_USER_BOOTTOOLS_PRINTBENV is not set
# CONFIG_USER_BOOTTOOLS_SETBENV is not set
# CONFIG_USER_BOOTTOOLS_RESET is not set

#
# MTD utils
#
# CONFIG_USER_MTDUTILS is not set
# CONFIG_USER_MTDUTILS_ERASE is not set
# CONFIG_USER_MTDUTILS_ERASEALL is not set
# CONFIG_USER_MTDUTILS_FTL_CHECK is not set
# CONFIG_USER_MTDUTILS_FTL_FORMAT is not set
# CONFIG_USER_MTDUTILS_MKFSJFFS is not set
# CONFIG_USER_MTDUTILS_MKFSJFFS2 is not set
# CONFIG_USER_MTDUTILS_NFTLDUMP is not set
# CONFIG_USER_MTDUTILS_NFTL_FORMAT is not set
# CONFIG_USER_MTDUTILS_NANDDUMP is not set
# CONFIG_USER_MTDUTILS_NANDTEST is not set
# CONFIG_USER_MTDUTILS_NANDWRITE is not set
# CONFIG_USER_MTDUTILS_DOC_LOADBIOS is not set
# CONFIG_USER_MTDUTILS_DOC_LOADIPL is not set

#
# Filesystem Applications
#
CONFIG_USER_FLATFSD_FLATFSD=y
CONFIG_USER_FLATFSD_AUTO=y
# CONFIG_USER_FLATFSD_USE_FLASH_FS is not set
# CONFIG_USER_FLATFSD_DISKLIKE is not set
CONFIG_USER_FLATFSD_COMPRESSED=y
CONFIG_USER_FLATFSD_HAS_RTC=y
# CONFIG_USER_MOUNT_MOUNT is not set
# CONFIG_USER_MOUNT_UMOUNT is not set
# CONFIG_USER_FDISK_FDISK is not set
# CONFIG_USER_FDISK_SFDISK is not set

#
# EXT2
#
# CONFIG_USER_E2FSPROGS_E2FSCK_E2FSCK is not set
# CONFIG_USER_E2FSPROGS_MISC_MKE2FS is not set
# CONFIG_USER_E2FSPROGS_MISC_BADBLOCKS is not set
# CONFIG_USER_E2FSPROGS_MISC_CHATTR is not set
# CONFIG_USER_E2FSPROGS_MISC_DUMPE2FS is not set
# CONFIG_USER_E2FSPROGS_MISC_E2LABEL is not set
# CONFIG_USER_E2FSPROGS_MISC_FSCK is not set
# CONFIG_USER_E2FSPROGS_MISC_LSATTR is not set
# CONFIG_USER_E2FSPROGS_MISC_MKLOST_FOUND is not set
# CONFIG_USER_E2FSPROGS_MISC_TUNE2FS is not set
# CONFIG_USER_E2FSPROGS_MISC_UUIDGEN is not set

#
# RESIERFS
#
# CONFIG_USER_REISERFSPROGS is not set
# CONFIG_USER_REISERFSPROGS_DEBUGRESIERFS is not set
# CONFIG_USER_REISERFSPROGS_MKREISERFS is not set
# CONFIG_USER_REISERFSPROGS_REISERFSCK is not set
# CONFIG_USER_REISERFSPROGS_RESIZE_REISERFS is not set
# CONFIG_USER_REISERFSPROGS_UNPACK is not set

#
# SAMBA
#
CONFIG_USER_SAMBA=y
# CONFIG_USER_SAMBA_SMBD is not set
# CONFIG_USER_SAMBA_NMBD is not set
CONFIG_USER_SAMBA_SMBMOUNT=y
CONFIG_USER_SAMBA_SMBUMOUNT=y
# CONFIG_USER_SAMBA_SHARED is not set

#
# SMBFS
#
# CONFIG_USER_SMBMOUNT_SMBMOUNT is not set
# CONFIG_USER_SMBMOUNT_SMBUMOUNT is not set

#
# CRAMFS
#
# CONFIG_USER_CRAMFS_CRAMFSCK is not set
# CONFIG_USER_CRAMFS_MKCRAMFS is not set

#
# MSDOS
#
# CONFIG_USER_DOSFSTOOLS_MKDOSFS is not set
# CONFIG_USER_DOSFSTOOLS_DOSFSCK is not set

#
# SquashFS
#
# CONFIG_USER_SQUASHFS_MKSQUASHFS is not set
# CONFIG_USER_SQUASHFS_MKSQUASHFS7Z is not set

#
# Network Applications
#
# CONFIG_USER_APPWEB_APPWEB is not set
# CONFIG_USER_ASTERISK is not set
CONFIG_USER_FNORD_HTTPD=y
# CONFIG_USER_FNORD_NOAUTH is not set
CONFIG_USER_FNORD_PAM=y
CONFIG_LIB_LIBPAM=y
CONFIG_USER_BPALOGIN_BPALOGIN=y
# CONFIG_USER_BR2684CTL_BR2684CTL is not set
# CONFIG_USER_BRCFG_BRCFG is not set
CONFIG_USER_BRCTL_BRCTL=y
CONFIG_USER_CLAMAV_CLAMAV=y
CONFIG_USER_CLAMAV_CLAMD=y
# CONFIG_USER_CLAMAV_CLAMDSCAN is not set
# CONFIG_USER_CLAMAV_CLAMSCAN is not set
CONFIG_USER_CLAMAV_FRESHCLAM=y
# CONFIG_USER_CLAMAV_SIGTOOL is not set
# CONFIG_USER_CLAMAV_TESTS is not set
# CONFIG_USER_CLAMAV_CLAMSMTP is not set
CONFIG_LIB_LIBBZ2=y
CONFIG_LIB_ZLIB=y
CONFIG_LIB_PTHREAD=y
CONFIG_USER_CONNTRACK_CONNTRACK=y
CONFIG_LIB_NFNETLINK=y
CONFIG_LIB_NETFILTER_CONNTRACK=y
# CONFIG_USER_CTORRENT_CTORRENT is not set
# CONFIG_USER_DHCPCD_DHCPCD is not set
CONFIG_USER_DHCPCD_NEW_DHCPCD=y
# CONFIG_USER_DHCPD_DHCPD is not set
CONFIG_USER_DHCP_ISC_SERVER_DHCPD=y
# CONFIG_USER_DHCP_ISC_CLIENT_DHCLIENT is not set
CONFIG_USER_DHCP_ISC_RELAY_DHCRELAY=y
CONFIG_USER_DIALD_DIALD=y
CONFIG_USER_DISCARD_DISCARD=y
CONFIG_USER_DISCARD_NO_INSTALL=y
CONFIG_USER_DISCARD_INETD_ECHO=y
CONFIG_USER_DISCARD_ECHO_NO_INSTALL=y
CONFIG_USER_DNSMASQ_DNSMASQ=y
# CONFIG_USER_DROPBEAR_DROPBEAR is not set
# CONFIG_USER_ETHATTACH_ETHATTACH is not set
CONFIG_USER_ETHERWAKE=y
# CONFIG_USER_ETHTOOL_ETHTOOL is not set
CONFIG_USER_EZIPUPDATE_EZIPUPDATE=y
# CONFIG_USER_FAKEIDENTD_IDENTD is not set
# CONFIG_USER_DDNS3_CLIENT_DDNS3 is not set
CONFIG_USER_FTP_FTP_FTP=y
# CONFIG_USER_FTPD_FTPD is not set
# CONFIG_USER_FROX_FROX is not set
# CONFIG_USER_FREESWAN is not set
CONFIG_USER_OPENSWAN=y
CONFIG_USER_OPENSWAN_PLUTO_PLUTO=y
CONFIG_LIB_LIBGMP=y
CONFIG_LIB_LIBDES=y
CONFIG_USER_OPENSWAN_PLUTO_WHACK=y
CONFIG_USER_OPENSWAN_UTILS_RANBITS=y
CONFIG_USER_OPENSWAN_UTILS_RSASIGKEY=y
CONFIG_LIB_LIBGMP=y
CONFIG_USER_OPENSWAN_KLIPS_EROUTE=y
CONFIG_USER_OPENSWAN_KLIPS_KLIPSDEBUG=y
CONFIG_USER_OPENSWAN_KLIPS_SPI=y
CONFIG_USER_OPENSWAN_KLIPS_SPIGRP=y
CONFIG_USER_OPENSWAN_KLIPS_TNCFG=y
# CONFIG_USER_HTTPD_HTTPD is not set
CONFIG_USER_HTTPTUNNEL_CLIENT=y
CONFIG_USER_HTTPTUNNEL_SERVER=y
# CONFIG_USER_IFATTACH_IFATTACH is not set
CONFIG_USER_INETD_INETD=y
# CONFIG_USER_IPCHAINS_IPCHAINS is not set
# CONFIG_USER_IPERF_IPERF is not set
# CONFIG_USER_IPFWADM_IPFWADM is not set
# CONFIG_USER_IPMASQADM_IPMASQADM is not set
# CONFIG_USER_IPPORTFW_IPPORTFW is not set
# CONFIG_USER_IPREDIR_IPREDIR is not set
CONFIG_USER_IPROUTE2=y
CONFIG_USER_IPROUTE2_TC_TC=y
# CONFIG_USER_IPROUTE2_IP_IFCFG is not set
CONFIG_USER_IPROUTE2_IP_IP=y
CONFIG_USER_IPROUTE2_IP_ROUTEF=y
CONFIG_USER_IPROUTE2_IP_ROUTEL=y
CONFIG_USER_IPROUTE2_IP_RTACCT=y
CONFIG_USER_IPROUTE2_IP_RTMON=y
# CONFIG_USER_IPROUTE2_IP_RTPR is not set
# CONFIG_USER_IPSENTINEL_IPSENTINEL is not set
CONFIG_USER_IPTABLES_IPTABLES=y
CONFIG_USER_IPTABLES_IP6TABLES=y
CONFIG_USER_IPUTILS_IPUTILS=y
CONFIG_USER_IPUTILS_PING=y
CONFIG_USER_IPUTILS_PING6=y
CONFIG_USER_IPUTILS_TRACEROUTE6=y
# CONFIG_USER_IPUTILS_RDISC is not set
# CONFIG_USER_IPUTILS_CLOCKDIFF is not set
# CONFIG_USER_IPUTILS_TFTPD is not set
# CONFIG_USER_IPUTILS_TRACEPATH is not set
CONFIG_USER_IPUTILS_TRACEPATH6=y
# CONFIG_USER_IPUTILS_ARPING is not set
# CONFIG_USER_IPUTILS_RARPD is not set
# CONFIG_USER_KENDIN_CONFIG is not set
# CONFIG_USER_KLAXON_KLAXON is not set
CONFIG_USER_L2TPD_L2TPD=y
CONFIG_USER_LINUXIGD_LINUXIGD=y
CONFIG_LIB_LIBUPNP=y
# CONFIG_USER_LINUXIGD_DEFAULT is not set
# CONFIG_USER_LOATTACH_LOATTACH is not set
# CONFIG_USER_LRPSTAT_LRPSTAT is not set
CONFIG_USER_SMTP_SMTPCLIENT=y
# CONFIG_USER_MAIL_MAIL_IP is not set
# CONFIG_USER_MARADNS_MARADNS is not set
# CONFIG_USER_MINI_HTTPD_MINI_HTTPD is not set
# CONFIG_USER_MSNTP_MSNTP is not set
# CONFIG_USER_NESSUS_NASL is not set
CONFIG_LIB_LIBPCAP=y
CONFIG_USER_NETCAT_NETCAT=y
# CONFIG_USER_NETPERF_NETPERF is not set
# CONFIG_USER_NETPERF_NETSERVER is not set
# CONFIG_USER_NETSTAT_NAT_NETSTAT_NAT is not set
CONFIG_USER_NETSNMP_SNMPD=y
# CONFIG_USER_NETSNMP_SNMPD_MINI is not set
# CONFIG_USER_NETSNMP_APPS is not set
# CONFIG_USER_NETSNMP_BUILDSTATIC is not set
# CONFIG_USER_NETSNMP_MANUALS is not set
# CONFIG_USER_NETSNMP_SCRIPTS is not set
# CONFIG_USER_NETSNMP_MIBS is not set
# CONFIG_USER_NETSNMP_NOV1 is not set
# CONFIG_USER_NETSNMP_NOV2C is not set
# CONFIG_USER_NETSNMP_IPV6 is not set
# CONFIG_USER_NETSNMP_NOTRANSPORTS is not set
# CONFIG_USER_NETSNMP_OPENSSL is not set
# CONFIG_USER_NETSNMP_OVRDEFAULTS is not set
# CONFIG_USER_NETSNMP_ADDMIBS is not set
# CONFIG_USER_MARADNS_ZONESERVER is not set
# CONFIG_USER_NTPCLIENT_NTPCLIENT is not set
# CONFIG_USER_NTPCLIENT_ADJTIMEX is not set
CONFIG_USER_NTPD_NTPD=y
# CONFIG_USER_NTPD_NTPDC is not set
# CONFIG_USER_NTPD_NTPDATE is not set
# CONFIG_USER_NTPD_NTPQ is not set
# CONFIG_USER_OPENSSL_APPS is not set
# CONFIG_USER_OPENVPN_OPENVPN is not set
CONFIG_LIB_LIBLZO=y
# CONFIG_USER_PING_PING is not set
# CONFIG_USER_PLUG_PLUG is not set
CONFIG_USER_POP3PROXY_POP3PROXY=y
CONFIG_USER_PORTMAP_PORTMAP=y
CONFIG_USER_PPPD_PPPD_PPPD=y
CONFIG_USER_PPPD_WITH_PAM=y
CONFIG_LIB_LIBPAM=y
CONFIG_USER_PPPD_WITH_MPPE=y
CONFIG_LIB_LIBDES=y
CONFIG_USER_PPPD_WITH_TACACS=y
CONFIG_USER_PPPD_WITH_RADIUS=y
CONFIG_USER_PPPD_WITH_PPPOE=y
# CONFIG_USER_PPPD_WITH_PPPOA is not set
CONFIG_USER_PPPD_PPPOE_RETRIES=5
CONFIG_USER_PPPD_NO_AT_REDIRECTION=y
CONFIG_USER_PPTPD_PPTPCTRL=y
CONFIG_USER_PPTPD_PPTPD=y
CONFIG_USER_PPTP_CLIENT_PPTP=y
CONFIG_USER_PPTP_CLIENT_PPTP_CALLMGR=y
# CONFIG_USER_PROFTPD_PROFTPD is not set
# CONFIG_USER_QUAGGA_ZEBRA_ZEBRA is not set
CONFIG_USER_RADVD_RADVD=y
CONFIG_LIB_FLEX=y
CONFIG_USER_RADAUTH_RADAUTH=y
# CONFIG_USER_RDATE_RDATE is not set
# CONFIG_USER_ROUTED_ROUTED is not set
# CONFIG_USER_RP_PPPOE_PPPOE is not set
# CONFIG_USER_RP_PPPOE_PPPOE_SERVER is not set
# CONFIG_USER_RSYNC_RSYNC is not set
# CONFIG_USER_RSYSLOGD_RSYSLOGD is not set
# CONFIG_USER_SER_SER is not set
# CONFIG_USER_SETHDLC_SETHDLC is not set
CONFIG_USER_SIPROXD_SIPROXD=y
CONFIG_LIB_OSIP2=y
# CONFIG_USER_SLATTACH_SLATTACH is not set
# CONFIG_USER_SNMPD_SNMPD is not set
CONFIG_USER_SNORT_SNORT=y
CONFIG_LIB_LIBPCRE=y
CONFIG_LIB_LIBNET=y
# CONFIG_USER_SPEEDTOUCH_MODEM_RUN is not set
# CONFIG_USER_STUNNEL_STUNNEL is not set
# CONFIG_USER_SSLWRAP_SSLWRAP is not set
CONFIG_USER_SQUID_SQUID=y
# CONFIG_USER_SSH_SSH is not set
# CONFIG_USER_SSH_SSHD is not set
# CONFIG_USER_SSH_SSHKEYGEN is not set
CONFIG_LIB_ZLIB=y
CONFIG_USER_SSH_SCP=y
# CONFIG_USER_STP_STP is not set
# CONFIG_USER_TCPWRAP_TCPD is not set
CONFIG_USER_TCPBLAST_TCPBLAST=y
CONFIG_USER_TCPDUMP_TCPDUMP=y
CONFIG_LIB_LIBPCAP=y
CONFIG_USER_TELNETD_TELNETD=y
# CONFIG_USER_TELNETD_DOES_NOT_USE_OPENPTY is not set
# CONFIG_USER_TELNET_TELNET is not set
# CONFIG_USER_TFTP_TFTP is not set
# CONFIG_USER_TFTPD_TFTPD is not set
# CONFIG_USER_THTTPD_THTTPD is not set
CONFIG_USER_TRACEROUTE_TRACEROUTE=y
# CONFIG_USER_UDEV is not set
# CONFIG_USER_ULOGD_ULOGD is not set
CONFIG_USER_ULOGD2_ULOGD=y
CONFIG_LIB_NFNETLINK=y
CONFIG_LIB_NETFILTER_LOG=y
CONFIG_LIB_NETFILTER_CONNTRACK=y
CONFIG_USER_VCONFIG_VCONFIG=y
# CONFIG_USER_VPNLED_VPNLED is not set
# CONFIG_USER_WGET is not set
CONFIG_USER_ZEBRA_ZEBRA_ZEBRA=y
CONFIG_USER_ZEBRA_BGPD_BGPD=y
CONFIG_USER_ZEBRA_OSPFD_OSPFD=y
CONFIG_USER_ZEBRA_RIPD_RIPD=y

#
# Net-tools
#
CONFIG_USER_NET_TOOLS_ARP=y
CONFIG_USER_NET_TOOLS_HOSTNAME=y
CONFIG_USER_NET_TOOLS_IFCONFIG=y
# CONFIG_USER_NET_TOOLS_NAMEIF is not set
CONFIG_USER_NET_TOOLS_NETSTAT=y
# CONFIG_USER_NET_TOOLS_PLIPCONFIG is not set
# CONFIG_USER_NET_TOOLS_RARP is not set
CONFIG_USER_NET_TOOLS_ROUTE=y
# CONFIG_USER_NET_TOOLS_SLATTACH is not set
CONFIG_USER_NET_TOOLS_MII_TOOL=y
# CONFIG_USER_NET_TOOLS_MII_TOOL_FEC is not set

#
# Wireless-tools
#
# CONFIG_USER_WIRELESS_TOOLS is not set
# CONFIG_USER_HOSTAP_HOSTAP is not set
# CONFIG_USER_WLAN_NG is not set

#
# Miscellaneous Applications
#
# CONFIG_USER_P7ZIP_7ZA is not set
# CONFIG_USER_LANG_A60 is not set
# CONFIG_USER_ARJ_ARJ is not set
# CONFIG_USER_BZIP2_BZIP2 is not set
# CONFIG_USER_CAL_CAL is not set
CONFIG_USER_CHAT_CHAT=y
# CONFIG_USER_CHAT_CHAT_NETWORK is not set
# CONFIG_USER_CKSUM_CKSUM is not set
# CONFIG_USER_CLOCK_CLOCK is not set
CONFIG_USER_CPU_CPU=y
# CONFIG_USER_CRYPTO_TOOLS_CRYPTOTEST is not set
# CONFIG_USER_CRYPTO_TOOLS_CRYPTOKEYTEST is not set
# CONFIG_USER_CAL_DATE is not set
# CONFIG_USER_DHRYSTONE_DHRYSTONE is not set
# CONFIG_USER_DE2TSCAL_DE2TSCAL is not set
# CONFIG_USER_EXPAT_EXAMPLES is not set
# CONFIG_USER_FLTHDR_FLTHDR is not set
# CONFIG_USER_FROB_LED_FROB_LED is not set
# CONFIG_USER_GDB_GDBREPLAY is not set
# CONFIG_USER_GDB_GDBSERVER is not set
# CONFIG_USER_GDB_TARGET is not set
# CONFIG_USER_GDB_HOST is not set
# CONFIG_USER_GDBSERVER_GDBREPLAY is not set
# CONFIG_USER_GDBSERVER_GDBSERVER is not set
# CONFIG_USER_GREP_GREP is not set
CONFIG_USER_HD_HD=y
# CONFIG_USER_LCD_LCD is not set
# CONFIG_USER_LEDCON_LEDCON is not set
# CONFIG_USER_LHA_LHA is not set
# CONFIG_USER_LILO_LILO is not set
# CONFIG_USER_LISSA_LISSA is not set
# CONFIG_USER_LPR is not set
# CONFIG_USER_LUA_LUA is not set
# CONFIG_USER_USBCBI_USBCBI is not set
# CONFIG_USER_USBISO_USBISO is not set
# CONFIG_USER_MATH_TEST is not set
CONFIG_USER_MAWK_AWK=y
CONFIG_USER_MYSQL=y
CONFIG_LIB_TERMCAP=y
CONFIG_USER_MYSQL_CLIB=y
# CONFIG_USER_NULL_NULL is not set
# CONFIG_USER_PALMBOT_PALMBOT is not set
# CONFIG_USER_PCMCIA_CS is not set
# CONFIG_USER_PERL_PERL is not set
# CONFIG_USER_PYTHON_PYTHON is not set
# CONFIG_USER_READPROFILE_READPROFILE is not set
# CONFIG_USER_ROOTLOADER_ROOTLOADER is not set
# CONFIG_USER_RRDTOOL_RRDTOOL is not set
# CONFIG_USER_SETSERIAL_SETSERIAL is not set
CONFIG_USER_SHADOW_UTILS=y
CONFIG_USER_SHADOW_PAM=y
CONFIG_LIB_LIBPAM=y
# CONFIG_USER_SHADOW_SHAREDLIB is not set
# CONFIG_USER_SHADOW_CHAGE is not set
# CONFIG_USER_SHADOW_CHFN is not set
# CONFIG_USER_SHADOW_CHPASSWD is not set
# CONFIG_USER_SHADOW_CHSH is not set
# CONFIG_USER_SHADOW_EXPIRY is not set
# CONFIG_USER_SHADOW_FAILLOG is not set
# CONFIG_USER_SHADOW_GPASSWD is not set
# CONFIG_USER_SHADOW_GROUPADD is not set
# CONFIG_USER_SHADOW_GROUPDEL is not set
# CONFIG_USER_SHADOW_GROUPMOD is not set
# CONFIG_USER_SHADOW_GROUPS is not set
# CONFIG_USER_SHADOW_GRPCK is not set
# CONFIG_USER_SHADOW_GRPCONV is not set
# CONFIG_USER_SHADOW_GRPUNCONV is not set
# CONFIG_USER_SHADOW_ID is not set
# CONFIG_USER_SHADOW_LASTLOG is not set
CONFIG_USER_SHADOW_LOGIN=y
# CONFIG_USER_SHADOW_LOGOUTD is not set
# CONFIG_USER_SHADOW_NEWGRP is not set
# CONFIG_USER_SHADOW_NEWUSERS is not set
# CONFIG_USER_SHADOW_NOLOGIN is not set
# CONFIG_USER_SHADOW_PASSWD is not set
# CONFIG_USER_SHADOW_PWCK is not set
# CONFIG_USER_SHADOW_PWCONV is not set
# CONFIG_USER_SHADOW_PWUNCONV is not set
# CONFIG_USER_SHADOW_SU is not set
# CONFIG_USER_SHADOW_SULOGIN is not set
# CONFIG_USER_SHADOW_USERADD is not set
# CONFIG_USER_SHADOW_USERDEL is not set
# CONFIG_USER_SHADOW_USERMOD is not set
# CONFIG_USER_SHADOW_VIPW is not set
# CONFIG_USER_TRIPWIRE_SIGGEN is not set
# CONFIG_USER_STRACE_STRACE is not set
# CONFIG_USER_STTY_STTY is not set
# CONFIG_USER_TCSH_TCSH is not set
# CONFIG_USER_TINYTCL_TCLSH is not set
# CONFIG_LIB_TINYTCL_STATIC is not set
# CONFIG_USER_THREADDEMOS_THREADDEMOS is not set
CONFIG_USER_TIP_TIP=y
# CONFIG_USER_TRIPWIRE_TRIPWIRE is not set
# CONFIG_USER_UNRAR_UNRAR is not set
# CONFIG_USER_UNZIP_UNZIP is not set
# CONFIG_USER_UNZOO_UNZOO is not set
# CONFIG_USER_LRZSZ_LRZSZ is not set

#
# Benchmarks
#
# CONFIG_USER_WHETSTONE_WHETSTONE is not set
# CONFIG_USER_NBENCH_NBENCH is not set

#
# LIRC
#
# CONFIG_USER_LIRC is not set
# CONFIG_USER_LIRC_LIRCD is not set
# CONFIG_USER_LIRC_IRRECORD is not set
# CONFIG_USER_LIRC_LIRCMD is not set
# CONFIG_USER_LIRC_IREXEC is not set
# CONFIG_USER_LIRC_IRW is not set
# CONFIG_USER_LIRC_MODE2 is not set

#
# LM SENSORS
#
# CONFIG_USER_LM_SENSORS is not set
# CONFIG_USER_LM_SENSORS_SENSORS is not set

#
# QSPI
#
# CONFIG_MCF_QSPI is not set
# CONFIG_USER_QSPITEST_TEST is not set
# CONFIG_USER_QSPITEST_RX is not set

#
# Editors
#
# CONFIG_USER_LEVEE_VI is not set
# CONFIG_USER_ELVISTINY_VI is not set

#
# Audio tools
#
# CONFIG_USER_MP3PLAY_MP3PLAY is not set
# CONFIG_USER_OGGPLAY_OGG123 is not set
# CONFIG_USER_OGGPLAY_EXAMPLE is not set
# CONFIG_USER_MUSICBOX_MUSICBOX is not set
# CONFIG_USER_PLAY_PLAY is not set
# CONFIG_USER_PLAY_TONE is not set
# CONFIG_USER_VPLAY_VPLAY is not set
# CONFIG_USER_VPLAY_VREC is not set
# CONFIG_USER_VPLAY_MIXER is not set
# CONFIG_USER_PLAYRT_PLAYRT is not set

#
# Video tools
#
# CONFIG_USER_CAMSERV is not set
# CONFIG_USER_W3CAM_VIDCAT is not set
# CONFIG_USER_W3CAM_W3CAMD is not set

#
# Fileutils tools
#
# CONFIG_USER_FILEUTILS_CAT is not set
# CONFIG_USER_FILEUTILS_CHGRP is not set
# CONFIG_USER_FILEUTILS_CHMOD is not set
# CONFIG_USER_FILEUTILS_CHOWN is not set
# CONFIG_USER_FILEUTILS_CMP is not set
# CONFIG_USER_FILEUTILS_CP is not set
# CONFIG_USER_FILEUTILS_DD is not set
# CONFIG_USER_FILEUTILS_GREP is not set
# CONFIG_USER_FILEUTILS_L is not set
# CONFIG_USER_FILEUTILS_LN is not set
# CONFIG_USER_FILEUTILS_LS is not set
# CONFIG_USER_FILEUTILS_MKDIR is not set
# CONFIG_USER_FILEUTILS_MKFIFO is not set
# CONFIG_USER_FILEUTILS_MKNOD is not set
# CONFIG_USER_FILEUTILS_MORE is not set
# CONFIG_USER_FILEUTILS_MV is not set
# CONFIG_USER_FILEUTILS_RM is not set
# CONFIG_USER_FILEUTILS_RMDIR is not set
# CONFIG_USER_FILEUTILS_SYNC is not set
# CONFIG_USER_FILEUTILS_TOUCH is not set

#
# Shutils tools
#
# CONFIG_USER_SHUTILS_BASENAME is not set
# CONFIG_USER_SHUTILS_DATE is not set
# CONFIG_USER_SHUTILS_DIRNAME is not set
# CONFIG_USER_SHUTILS_ECHO is not set
# CONFIG_USER_SHUTILS_FALSE is not set
# CONFIG_USER_SHUTILS_LOGNAME is not set
# CONFIG_USER_SHUTILS_PRINTENV is not set
# CONFIG_USER_SHUTILS_PWD is not set
# CONFIG_USER_SHUTILS_TRUE is not set
# CONFIG_USER_SHUTILS_UNAME is not set
# CONFIG_USER_SHUTILS_WHICH is not set
# CONFIG_USER_SHUTILS_WHOAMI is not set
# CONFIG_USER_SHUTILS_YES is not set

#
# Sysutils tools
#
# CONFIG_USER_SYSUTILS_REBOOT is not set
# CONFIG_USER_SYSUTILS_SHUTDOWN is not set
# CONFIG_USER_SYSUTILS_DF is not set
# CONFIG_USER_SYSUTILS_FREE is not set
# CONFIG_USER_SYSUTILS_HOSTNAME is not set
# CONFIG_USER_SYSUTILS_KILL is not set
# CONFIG_USER_SYSUTILS_PS is not set

#
# Procps tools
#
# CONFIG_USER_PROCPS_FREE is not set
# CONFIG_USER_PROCPS_KILL is not set
# CONFIG_USER_PROCPS_PGREP is not set
# CONFIG_USER_PROCPS_PKILL is not set
# CONFIG_USER_PROCPS_PS is not set
# CONFIG_USER_PROCPS_SNICE is not set
CONFIG_USER_PROCPS_SYSCTL=y
CONFIG_USER_PROCPS_TLOAD=y
# CONFIG_USER_PROCPS_TOP is not set
# CONFIG_USER_PROCPS_UPTIME is not set
CONFIG_USER_PROCPS_VMSTAT=y
CONFIG_USER_PROCPS_W=y
# CONFIG_USER_PROCPS_WATCH is not set

#
# PCI utilities
#
# CONFIG_USER_PCIUTILS_LSPCI is not set
# CONFIG_USER_PCIUTILS_SETPCI is not set

#
# 
#
# CONFIG_USER_CXXTEST_CXXTEST is not set

#
# BusyBox
#
CONFIG_USER_BUSYBOX_BUSYBOX=y

#
# Applets
#
# CONFIG_USER_BUSYBOX_ADDGROUP is not set
# CONFIG_USER_BUSYBOX_ADDUSER is not set
# CONFIG_USER_BUSYBOX_ADJTIMEX is not set
# CONFIG_USER_BUSYBOX_AR is not set
CONFIG_USER_BUSYBOX_ARPING=y
# CONFIG_USER_BUSYBOX_AWK is not set
CONFIG_USER_BUSYBOX_BASENAME=y
# CONFIG_USER_BUSYBOX_BUNZIP2 is not set
# CONFIG_USER_BUSYBOX_CAL is not set
CONFIG_USER_BUSYBOX_CAT=y
CONFIG_USER_BUSYBOX_CHGRP=y
CONFIG_USER_BUSYBOX_CHMOD=y
CONFIG_USER_BUSYBOX_CHOWN=y
CONFIG_USER_BUSYBOX_CHROOT=y
# CONFIG_USER_BUSYBOX_CHVT is not set
CONFIG_USER_BUSYBOX_CLEAR=y
CONFIG_USER_BUSYBOX_CMP=y
CONFIG_USER_BUSYBOX_CP=y
# CONFIG_USER_BUSYBOX_PRESERVE_HARDLINKS is not set
CONFIG_USER_BUSYBOX_CPIO=y
# CONFIG_USER_BUSYBOX_CROND is not set
# CONFIG_USER_BUSYBOX_CRONTAB is not set
CONFIG_USER_BUSYBOX_CUT=y
CONFIG_USER_BUSYBOX_DATE=y
# CONFIG_USER_BUSYBOX_DATE_ISOFMT is not set
# CONFIG_USER_BUSYBOX_DC is not set
CONFIG_USER_BUSYBOX_DD=y
# CONFIG_USER_BUSYBOX_DEALLOCVT is not set
# CONFIG_USER_BUSYBOX_DELGROUP is not set
# CONFIG_USER_BUSYBOX_DELUSER is not set
# CONFIG_USER_BUSYBOX_DEVFSD is not set
CONFIG_USER_BUSYBOX_DF=y
CONFIG_USER_BUSYBOX_DIRNAME=y
CONFIG_USER_BUSYBOX_DMESG=y
CONFIG_USER_BUSYBOX_DOS2UNIX=y
# CONFIG_USER_BUSYBOX_DPKG is not set
# CONFIG_USER_BUSYBOX_DPKG_DEB is not set
# CONFIG_USER_BUSYBOX_DUTMP is not set
CONFIG_USER_BUSYBOX_DU=y
# CONFIG_USER_BUSYBOX_DU_DEFALT_BLOCKSIZE_1K is not set
# CONFIG_USER_BUSYBOX_DUMPKMAP is not set
# CONFIG_USER_BUSYBOX_ECHO is not set
CONFIG_USER_BUSYBOX_ENV=y
CONFIG_USER_BUSYBOX_EXPR=y
# CONFIG_USER_BUSYBOX_FBSET is not set
# CONFIG_USER_BUSYBOX_FDFLUSH is not set
# CONFIG_USER_BUSYBOX_FDFORMAT is not set
# CONFIG_USER_BUSYBOX_FDISK is not set
CONFIG_USER_BUSYBOX_FIND=y
CONFIG_USER_BUSYBOX_FIND_TYPE=y
CONFIG_USER_BUSYBOX_FIND_PERM=y
CONFIG_USER_BUSYBOX_FIND_MTIME=y
CONFIG_USER_BUSYBOX_FIND_NEWER=y
# CONFIG_USER_BUSYBOX_FIND_INUM is not set
# CONFIG_USER_BUSYBOX_FIND_XDEV is not set
# CONFIG_USER_BUSYBOX_FOLD is not set
CONFIG_USER_BUSYBOX_FREE=y
CONFIG_USER_BUSYBOX_FREERAMDISK=y
# CONFIG_USER_BUSYBOX_FSCK_MINIX is not set
# CONFIG_USER_BUSYBOX_FTPGET is not set
# CONFIG_USER_BUSYBOX_FTPPUT is not set
# CONFIG_USER_BUSYBOX_GETOPT is not set
# CONFIG_USER_BUSYBOX_GETTY is not set
CONFIG_USER_BUSYBOX_GREP=y
CONFIG_USER_BUSYBOX_GREP_CONTEXT=y
CONFIG_USER_BUSYBOX_GREP_EGREP_ALIAS=y
# CONFIG_USER_BUSYBOX_GREP_FGREP_ALIAS is not set
CONFIG_USER_BUSYBOX_GUNZIP=y
# CONFIG_USER_BUSYBOX_GUNZIP_UNCOMPRESS is not set
CONFIG_USER_BUSYBOX_GZIP=y
# CONFIG_USER_BUSYBOX_HALT is not set
# CONFIG_USER_BUSYBOX_HDPARM is not set
CONFIG_USER_BUSYBOX_HEAD=y
# CONFIG_USER_BUSYBOX_FANCY_HEAD is not set
# CONFIG_USER_BUSYBOX_HEXDUMP is not set
# CONFIG_USER_BUSYBOX_HOSTID is not set
# CONFIG_USER_BUSYBOX_HOSTNAME is not set
# CONFIG_USER_BUSYBOX_HTTPD is not set
# CONFIG_USER_BUSYBOX_HWCLOCK is not set
CONFIG_USER_BUSYBOX_ID=y
# CONFIG_USER_BUSYBOX_IFCONFIG is not set
# CONFIG_USER_BUSYBOX_IFUPDOWN is not set
# CONFIG_USER_BUSYBOX_INETD is not set
# CONFIG_USER_BUSYBOX_INIT is not set
CONFIG_USER_BUSYBOX_INSMOD=y
CONFIG_USER_BUSYBOX_LSMOD=y
CONFIG_USER_BUSYBOX_MODPROBE=y
CONFIG_USER_BUSYBOX_RMMOD=y
# CONFIG_USER_BUSYBOX_2_2_MODULES is not set
# CONFIG_USER_BUSYBOX_2_4_MODULES is not set
CONFIG_USER_BUSYBOX_2_6_MODULES=y
# CONFIG_USER_BUSYBOX_INSMOD_VERSION_CHECKING is not set
CONFIG_USER_BUSYBOX_CHECK_TAINTED_MODULE=y
# CONFIG_USER_BUSYBOX_INSMOD_LOADINKMEM is not set
# CONFIG_USER_BUSYBOX_IPADDR is not set
# CONFIG_USER_BUSYBOX_IPCALC is not set
# CONFIG_USER_BUSYBOX_IPLINK is not set
# CONFIG_USER_BUSYBOX_IPROUTE is not set
# CONFIG_USER_BUSYBOX_IPTUNNEL is not set
CONFIG_USER_BUSYBOX_KILL=y
CONFIG_USER_BUSYBOX_KILLALL=y
CONFIG_USER_BUSYBOX_KLOGD=y
# CONFIG_USER_BUSYBOX_LENGTH is not set
# CONFIG_USER_BUSYBOX_LAST is not set
CONFIG_USER_BUSYBOX_LN=y
# CONFIG_USER_BUSYBOX_LOADACM is not set
# CONFIG_USER_BUSYBOX_LOADFONT is not set
# CONFIG_USER_BUSYBOX_LOADKMAP is not set
CONFIG_USER_BUSYBOX_LOGGER=y
# CONFIG_USER_BUSYBOX_LOGIN is not set
# CONFIG_USER_BUSYBOX_LOGNAME is not set
# CONFIG_USER_BUSYBOX_LOGREAD is not set
# CONFIG_USER_BUSYBOX_LOSETUP is not set
CONFIG_USER_BUSYBOX_LS=y
CONFIG_USER_BUSYBOX_LS_USERNAME=y
CONFIG_USER_BUSYBOX_LS_TIMESTAMPS=y
CONFIG_USER_BUSYBOX_LS_FILETYPES=y
CONFIG_USER_BUSYBOX_LS_SORTFILES=y
CONFIG_USER_BUSYBOX_LS_RECURSIVE=y
CONFIG_USER_BUSYBOX_LS_FOLLOWLINKS=y
# CONFIG_USER_BUSYBOX_LS_COLOR is not set
# CONFIG_USER_BUSYBOX_MAKEDEVS is not set
CONFIG_USER_BUSYBOX_MD5SUM=y
# CONFIG_USER_BUSYBOX_MD5_SHA1_SUM_CHECK is not set
# CONFIG_USER_BUSYBOX_MESG is not set
CONFIG_USER_BUSYBOX_MKDIR=y
CONFIG_USER_BUSYBOX_MKFIFO=y
# CONFIG_USER_BUSYBOX_MKFS_MINIX is not set
CONFIG_USER_BUSYBOX_MKNOD=y
# CONFIG_USER_BUSYBOX_MKSWAP is not set
CONFIG_USER_BUSYBOX_MKTEMP=y
CONFIG_USER_BUSYBOX_MORE=y
# CONFIG_USER_BUSYBOX_USE_TERMIOS is not set
CONFIG_USER_BUSYBOX_MOUNT=y
CONFIG_USER_BUSYBOX_MOUNT_LOOP=y
# CONFIG_USER_BUSYBOX_MTAB_SUPPORT is not set
CONFIG_USER_BUSYBOX_NFSMOUNT=y
# CONFIG_USER_BUSYBOX_MT is not set
CONFIG_USER_BUSYBOX_MV=y
# CONFIG_USER_BUSYBOX_NAMEIF is not set
CONFIG_USER_BUSYBOX_NC=y
# CONFIG_USER_BUSYBOX_NETSTAT is not set
CONFIG_USER_BUSYBOX_NSLOOKUP=y
# CONFIG_USER_BUSYBOX_OD is not set
# CONFIG_USER_BUSYBOX_OPENVT is not set
# CONFIG_USER_BUSYBOX_PASSWD is not set
# CONFIG_USER_BUSYBOX_PATCH is not set
CONFIG_USER_BUSYBOX_PIDOF=y
# CONFIG_USER_BUSYBOX_PING is not set
# CONFIG_USER_BUSYBOX_PING6 is not set
# CONFIG_USER_BUSYBOX_PIPE_PROGRESS is not set
# CONFIG_USER_BUSYBOX_PIVOT_ROOT is not set
# CONFIG_USER_BUSYBOX_POWEROFF is not set
# CONFIG_USER_BUSYBOX_PRINTF is not set
CONFIG_USER_BUSYBOX_PS=y
CONFIG_USER_BUSYBOX_PWD=y
CONFIG_USER_BUSYBOX_RDATE=y
# CONFIG_USER_BUSYBOX_REALPATH is not set
CONFIG_USER_BUSYBOX_READLINK=y
CONFIG_USER_BUSYBOX_REBOOT=y
CONFIG_USER_BUSYBOX_RENICE=y
CONFIG_USER_BUSYBOX_RESET=y
CONFIG_USER_BUSYBOX_RM=y
CONFIG_USER_BUSYBOX_RMDIR=y
# CONFIG_USER_BUSYBOX_ROUTE is not set
# CONFIG_USER_BUSYBOX_RPM2CPIO is not set
# CONFIG_USER_BUSYBOX_RUN_PARTS is not set
# CONFIG_USER_BUSYBOX_RX is not set
CONFIG_USER_BUSYBOX_SED=y
# CONFIG_USER_BUSYBOX_SEQ is not set
# CONFIG_USER_BUSYBOX_SETKEYCODES is not set
# CONFIG_USER_BUSYBOX_SHELL is not set
# CONFIG_USER_BUSYBOX_SHA1SUM is not set
CONFIG_USER_BUSYBOX_SLEEP=y
# CONFIG_USER_BUSYBOX_FANCY_SLEEP is not set
CONFIG_USER_BUSYBOX_SORT=y
CONFIG_USER_BUSYBOX_SORT_REVERSE=y
CONFIG_USER_BUSYBOX_SORT_UNIQUE=y
# CONFIG_USER_BUSYBOX_START_STOP_DAEMON is not set
# CONFIG_USER_BUSYBOX_STRINGS is not set
CONFIG_USER_BUSYBOX_STTY=y
# CONFIG_USER_BUSYBOX_SU is not set
# CONFIG_USER_BUSYBOX_SULOGIN is not set
# CONFIG_USER_BUSYBOX_SWAPONOFF is not set
CONFIG_USER_BUSYBOX_SYNC=y
# CONFIG_USER_BUSYBOX_SYSCTL is not set
CONFIG_USER_BUSYBOX_SYSLOGD=y
CONFIG_USER_BUSYBOX_ROTATE_LOGFILE=y
CONFIG_USER_BUSYBOX_REMOTE_LOG=y
# CONFIG_USER_BUSYBOX_IPC_SYSLOG is not set
CONFIG_USER_BUSYBOX_TAIL=y
CONFIG_USER_BUSYBOX_FANCY_TAIL=y
CONFIG_USER_BUSYBOX_TAR=y
CONFIG_USER_BUSYBOX_TAR_CREATE=y
CONFIG_USER_BUSYBOX_TAR_EXCLUDE=y
# CONFIG_USER_BUSYBOX_TAR_GZIP is not set
# CONFIG_USER_BUSYBOX_TAR_BZIP2 is not set
# CONFIG_USER_BUSYBOX_TAR_COMPRESS is not set
# CONFIG_USER_BUSYBOX_TAR_FROM is not set
# CONFIG_USER_BUSYBOX_TAR_GNU_EXTENSIONS is not set
# CONFIG_USER_BUSYBOX_TAR_LONG_OPTIONS is not set
# CONFIG_USER_BUSYBOX_TAR_OLDGNU_COMPATABILITY is not set
CONFIG_USER_BUSYBOX_TEE=y
# CONFIG_USER_BUSYBOX_TEE_USE_BLOCK_IO is not set
CONFIG_USER_BUSYBOX_TELNET=y
CONFIG_USER_BUSYBOX_TELNET_TTYPE=y
# CONFIG_USER_BUSYBOX_TELNET_AUTOLOGIN is not set
# CONFIG_USER_BUSYBOX_TELNETD is not set
CONFIG_USER_BUSYBOX_TEST=y
# CONFIG_USER_BUSYBOX_TEST_64 is not set
CONFIG_USER_BUSYBOX_TFTP=y
CONFIG_USER_BUSYBOX_TFTP_PUT=y
CONFIG_USER_BUSYBOX_TFTP_GET=y
# CONFIG_USER_BUSYBOX_TFTP_BLOCKSIZE is not set
# CONFIG_USER_BUSYBOX_TFTP_DEBUG is not set
CONFIG_USER_BUSYBOX_TIME=y
CONFIG_USER_BUSYBOX_TOP=y
CONFIG_USER_BUSYBOX_CPU_USAGE_PERCENTAGE=y
CONFIG_USER_BUSYBOX_TOUCH=y
CONFIG_USER_BUSYBOX_TR=y
# CONFIG_USER_BUSYBOX_TRACEROUTE is not set
CONFIG_USER_BUSYBOX_TRUE_FALSE=y
CONFIG_USER_BUSYBOX_TTY=y
# CONFIG_USER_BUSYBOX_UDHCPC is not set
# CONFIG_USER_BUSYBOX_UDHCPD is not set
CONFIG_USER_BUSYBOX_UMOUNT=y
CONFIG_USER_BUSYBOX_MOUNT_FORCE=y
CONFIG_USER_BUSYBOX_UNAME=y
# CONFIG_USER_BUSYBOX_UNCOMPRESS is not set
CONFIG_USER_BUSYBOX_UNIQ=y
CONFIG_USER_BUSYBOX_UNIX2DOS=y
# CONFIG_USER_BUSYBOX_UPDATE is not set
CONFIG_USER_BUSYBOX_UPTIME=y
CONFIG_USER_BUSYBOX_USLEEP=y
CONFIG_USER_BUSYBOX_UUDECODE=y
CONFIG_USER_BUSYBOX_UUENCODE=y
CONFIG_USER_BUSYBOX_UNZIP=y
# CONFIG_USER_BUSYBOX_VCONFIG is not set
CONFIG_USER_BUSYBOX_VI=y
CONFIG_USER_BUSYBOX_VI_COLON=y
CONFIG_USER_BUSYBOX_VI_YANKMARK=y
CONFIG_USER_BUSYBOX_VI_SEARCH=y
CONFIG_USER_BUSYBOX_VI_USE_SIGNALS=y
CONFIG_USER_BUSYBOX_VI_DOT_CMD=y
CONFIG_USER_BUSYBOX_VI_READONLY=y
CONFIG_USER_BUSYBOX_VI_SETOPTS=y
CONFIG_USER_BUSYBOX_VI_SET=y
CONFIG_USER_BUSYBOX_VI_WIN_RESIZE=y
# CONFIG_USER_BUSYBOX_VI_OPTIMIZE_CURSOR is not set
CONFIG_USER_BUSYBOX_WATCHDOGD=y
CONFIG_USER_BUSYBOX_WC=y
CONFIG_USER_BUSYBOX_WGET=y
CONFIG_USER_BUSYBOX_WGET_STATUSBAR=y
CONFIG_USER_BUSYBOX_WGET_AUTHENTICATION=y
# CONFIG_USER_BUSYBOX_WGET_IP6_LITERAL is not set
CONFIG_USER_BUSYBOX_WHICH=y
# CONFIG_USER_BUSYBOX_WHOAMI is not set
CONFIG_USER_BUSYBOX_XARGS=y
# CONFIG_USER_BUSYBOX_XARGS_SUPPORT_CONFIRMATION is not set
# CONFIG_USER_BUSYBOX_XARGS_SUPPORT_QUOTES is not set
# CONFIG_USER_BUSYBOX_XARGS_SUPPORT_TERMOPT is not set
# CONFIG_USER_BUSYBOX_XARGS_SUPPORT_ZERO_TERM is not set
CONFIG_USER_BUSYBOX_YES=y
CONFIG_USER_BUSYBOX_ZIP=y

#
# other features
#
# CONFIG_USER_BUSYBOX_BUFFERS_GO_ON_STACK is not set
# CONFIG_USER_BUSYBOX_BUFFERS_GO_IN_BSS is not set
# CONFIG_USER_BUSYBOX_USE_DEVPS_PATCH is not set
CONFIG_USER_BUSYBOX_VERBOSE_USAGE=y
CONFIG_USER_BUSYBOX_AUTOWIDTH=y
# CONFIG_USER_BUSYBOX_EXTRA_QUIET is not set
# CONFIG_USER_BUSYBOX_MINIX2 is not set
# CONFIG_USER_BUSYBOX_USE_BB_PWD_GRP is not set
# CONFIG_USER_BUSYBOX_DMALLOC is not set
# CONFIG_USER_BUSYBOX_EFENCE is not set
# CONFIG_USER_BUSYBOX_BUFFERS_USE_MALLOC is not set
# CONFIG_USER_BUSYBOX_DEVFS is not set
# CONFIG_USER_BUSYBOX_DEVPTS is not set
# CONFIG_USER_BUSYBOX_SUID is not set
# CONFIG_USER_BUSYBOX_LFS is not set
# CONFIG_USER_BUSYBOX_SELINUX is not set
# CONFIG_USER_BUSYBOX_STATIC is not set
# CONFIG_USER_BUSYBOX_UNARCHIVE_TAPE is not set
# CONFIG_USER_BUSYBOX_IPV6 is not set
# CONFIG_USER_BUSYBOX_CLEAN_UP is not set
CONFIG_USER_BUSYBOX_HUMAN_READABLE=y
# CONFIG_USER_BUSYBOX_LOCALE_SUPPORT is not set
CONFIG_USER_BUSYBOX_CPU_USAGE_PERCENTAGE=y

#
# Tinylogin
#
# CONFIG_USER_TINYLOGIN_TINYLOGIN is not set

#
# MicroWindows
#
# CONFIG_USER_MICROWIN is not set

#
# Games
#
# CONFIG_USER_GAMES_ADVENT4 is not set
# CONFIG_USER_GAMES_DUNGEON is not set
# CONFIG_USER_GAMES_RUBIK is not set

#
# Miscellaneous Configuration
#
CONFIG_USER_RAMIMAGE_NONE=y
# CONFIG_USER_RAMIMAGE_RAMFS64 is not set
# CONFIG_USER_RAMIMAGE_RAMFS128 is not set
# CONFIG_USER_RAMIMAGE_RAMFS256 is not set
# CONFIG_USER_RAMIMAGE_RAMFS512 is not set
# CONFIG_USER_RAMIMAGE_RAMFS1024 is not set
# CONFIG_USER_RAMIMAGE_RAMFS2048 is not set
# CONFIG_USER_RAMIMAGE_RAMFS8192 is not set
# CONFIG_USER_CGI_GENERIC is not set
# CONFIG_USER_CGIHTML is not set
# CONFIG_USER_DEMO_BUTTON is not set
# CONFIG_USER_DEMO_LATCH is not set
# CONFIG_USER_DEMO_MORSE is not set
# CONFIG_USER_DEMO_R2100 is not set
CONFIG_POOR_ENTROPY=y

#
# Debug Builds
#
# CONFIG_LIB_DEBUG is not set
# CONFIG_USER_DEBUG is not set

#
# Debug tools
#
# CONFIG_USER_TIMEPEG_TPT is not set

#
# Debug libraries
#
# CONFIG_LIB_LIBCCMALLOC is not set
