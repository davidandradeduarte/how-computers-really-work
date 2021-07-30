# View services/daemons - from "How Computers Really Work" book, by Matthew Justice

```bash
systemctl list-units --type=service --state=running
```

```
UNIT                        LOAD   ACTIVE SUB     DESCRIPTION
alsa-state.service          loaded active running Manage Sound Card State (restore and store)
avahi-daemon.service        loaded active running Avahi mDNS/DNS-SD Stack
bluealsa.service            loaded active running BluezALSA proxy
bluetooth.service           loaded active running Bluetooth service
containerd.service          loaded active running containerd container runtime
cron.service                loaded active running Regular background program processing daemon
dbus.service                loaded active running D-Bus System Message Bus
dhcpcd.service              loaded active running dhcpcd on all interfaces
docker.service              loaded active running Docker Application Container Engine
getty@tty1.service          loaded active running Getty on tty1
hciuart.service             loaded active running Configure Bluetooth Modems connected by UART
lighttpd.service            loaded active running Lighttpd Daemon
ModemManager.service        loaded active running Modem Manager
NetworkManager.service      loaded active running Network Manager
polkit.service              loaded active running Authorization Manager
rng-tools.service           loaded active running rng-tools.service
rsyslog.service             loaded active running System Logging Service
ssh.service                 loaded active running OpenBSD Secure Shell server
systemd-journald.service    loaded active running Journal Service
systemd-logind.service      loaded active running Login Service
systemd-timesyncd.service   loaded active running Network Time Synchronization
systemd-udevd.service       loaded active running udev Kernel Device Manager
triggerhappy.service        loaded active running triggerhappy global hotkey daemon
udisks2.service             loaded active running Disk Manager
unattended-upgrades.service loaded active running Unattended Upgrades Shutdown
user@1000.service           loaded active running User Manager for UID 1000
user@999.service            loaded active running User Manager for UID 999
wpa_supplicant.service      loaded active running WPA supplicant
xrdp-sesman.service         loaded active running xrdp session manager
xrdp.service                loaded active running xrdp daemon

LOAD   = Reflects whether the unit definition was properly loaded.
ACTIVE = The high-level unit activation state, i.e. generalization of SUB.
SUB    = The low-level unit activation state, values depend on unit type.

30 loaded units listed. Pass --all to see loaded but inactive units, too.
To show all installed unit files use 'systemctl list-unit-files'.
```

view details of a particular service (e.g `cron.service`)

```bash
systemctl status cron.service
```

```
● cron.service - Regular background program processing daemon
   Loaded: loaded (/lib/systemd/system/cron.service; enabled; vendor preset: enabled)
   Active: active (running) since Sun 2021-07-25 01:24:01 BST; 21h ago
     Docs: man:cron(8)
 Main PID: 339 (cron)
    Tasks: 1 (limit: 3862)
   CGroup: /system.slice/cron.service
           └─339 /usr/sbin/cron -f

Jul 25 22:10:01 raspberrypi CRON[22601]: pam_unix(cron:session): session closed for user root
Jul 25 22:17:01 raspberrypi CRON[22706]: pam_unix(cron:session): session opened for user root by (uid=0
Jul 25 22:17:01 raspberrypi CRON[22710]: (root) CMD (   cd / && run-parts --report /etc/cron.hourly)
Jul 25 22:17:01 raspberrypi CRON[22706]: pam_unix(cron:session): session closed for user root
Jul 25 22:20:01 raspberrypi CRON[22763]: pam_unix(cron:session): session opened for user root by (uid=0
Jul 25 22:20:01 raspberrypi CRON[22767]: (root) CMD (   PATH="$PATH:/usr/sbin:/usr/local/bin/" pihole u
Jul 25 22:20:01 raspberrypi CRON[22763]: pam_unix(cron:session): session closed for user root
Jul 25 22:30:01 raspberrypi CRON[22971]: pam_unix(cron:session): session opened for user root by (uid=0
Jul 25 22:30:01 raspberrypi CRON[22975]: (root) CMD (   PATH="$PATH:/usr/sbin:/usr/local/bin/" pihole u
Jul 25 22:30:01 raspberrypi CRON[22971]: pam_unix(cron:session): session closed for user root
```
