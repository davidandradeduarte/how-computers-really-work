# View loaded kernel modules - from "How Computers Really Work" book, by Matthew Justice

device drivers are implemented as kernel modeules on linux
```bash
lsmod
```

or

```bash
cat /proc/modules
```

```
Module                  Size  Used by
veth                   28672  0
xt_conntrack           16384  1
xt_MASQUERADE          16384  1
nf_conntrack_netlink    45056  0
nft_counter            16384  15
xt_addrtype            16384  2
nft_compat             20480  4
nft_chain_nat          16384  4
nf_nat                 49152  2 xt_MASQUERADE,nft_chain_nat
nf_conntrack          131072  4 xt_MASQUERADE,nf_conntrack_netlink,xt_conntrack,nf_nat
nf_defrag_ipv4         16384  1 nf_conntrack
nf_tables             143360  45 nft_compat,nft_chain_nat,nft_counter
nfnetlink              16384  4 nft_compat,nf_conntrack_netlink,nf_tables
br_netfilter           28672  0
bridge                143360  1 br_netfilter
cmac                   16384  1
rfcomm                 45056  4
bnep                   20480  2
hci_uart               40960  1
btbcm                  16384  1 hci_uart
bluetooth             376832  29 hci_uart,bnep,btbcm,rfcomm
ecdh_generic           16384  2 bluetooth
ecc                    32768  1 ecdh_generic
overlay               102400  2
8021q                  32768  0
garp                   16384  1 8021q
stp                    16384  2 garp,bridge
llc                    16384  3 garp,bridge,stp
sg                     28672  0
v3d                    69632  0
brcmfmac              319488  0
gpu_sched              36864  1 v3d
brcmutil               16384  1 brcmfmac
vc4                   237568  0
cec                    49152  1 vc4
sha256_generic         16384  0
libsha256              20480  1 sha256_generic
drm_kms_helper        184320  2 vc4
raspberrypi_hwmon      16384  0
cfg80211              679936  1 brcmfmac
rfkill                 28672  6 bluetooth,cfg80211
drm                   458752  5 v3d,vc4,gpu_sched,drm_kms_helper
drm_panel_orientation_quirks    16384  1 drm
bcm2835_v4l2           45056  0
bcm2835_codec          36864  0
v4l2_mem2mem           32768  1 bcm2835_codec
bcm2835_isp            32768  0
bcm2835_mmal_vchiq     28672  3 bcm2835_isp,bcm2835_codec,bcm2835_v4l2
videobuf2_vmalloc      16384  1 bcm2835_v4l2
videobuf2_dma_contig    20480  2 bcm2835_isp,bcm2835_codec
snd_soc_core          200704  1 vc4
snd_bcm2835            24576  1
videobuf2_memops       16384  2 videobuf2_dma_contig,videobuf2_vmalloc
videobuf2_v4l2         28672  4 bcm2835_isp,bcm2835_codec,bcm2835_v4l2,v4l2_mem2mem
videobuf2_common       57344  5 bcm2835_isp,bcm2835_codec,bcm2835_v4l2,v4l2_mem2mem,videobuf2_v4l2
snd_compress           20480  1 snd_soc_core
snd_pcm_dmaengine      16384  1 snd_soc_core
videodev              237568  6 bcm2835_isp,bcm2835_codec,videobuf2_common,bcm2835_v4l2,v4l2_mem2mem,videobuf2_v4l2
snd_pcm                98304  4 vc4,snd_pcm_dmaengine,snd_bcm2835,snd_soc_core
vc_sm_cma              32768  2 bcm2835_isp,bcm2835_mmal_vchiq
mc                     45056  6 bcm2835_isp,bcm2835_codec,videobuf2_common,videodev,v4l2_mem2mem,videobuf2_v4l2
snd_timer              32768  1 snd_pcm
snd                    73728  7 snd_compress,snd_timer,snd_bcm2835,snd_soc_core,snd_pcm
syscopyarea            16384  1 drm_kms_helper
sysfillrect            16384  1 drm_kms_helper
sysimgblt              16384  1 drm_kms_helper
fb_sys_fops            16384  1 drm_kms_helper
rpivid_mem             16384  0
uio_pdrv_genirq        16384  0
uio                    20480  1 uio_pdrv_genirq
i2c_dev                16384  0
ip_tables              28672  0
x_tables               32768  5 ip_tables,nft_compat,xt_MASQUERADE,xt_addrtype,xt_conntrack
ipv6                  450560  77 br_netfilter,bridge
nf_defrag_ipv6         20480  2 nf_conntrack,ipv6
```

to get more info about a specific module (e.g `snd` - audio driver)
```bash
modinfo snd
```

```
filename:       /lib/modules/5.4.51-v7l+/kernel/sound/core/snd.ko
alias:          char-major-116-*
license:        GPL
description:    Advanced Linux Sound Architecture driver for soundcards.
author:         Jaroslav Kysela <perex@perex.cz>
srcversion:     79A188CFF6307B634898603
depends:
intree:         Y
name:           snd
vermagic:       5.4.51-v7l+ SMP mod_unload modversions ARMv7 p2v8
parm:           slots:Module names assigned to the slots. (array of charp)
parm:           major:Major # for sound driver. (int)
parm:           cards_limit:Count of auto-loadable soundcards. (int)
```