Chapter 3.and 4.


1. Build library
----------------
cd ../lib
make clean
make all


2. Set a link to the library
----------------------------
sudo ln -s <path_to_lib>/lib/libtcpip.so /usr/local/lib/


3. Build server/clinet apps
---------------------------
make all
or 
make daytimetcpsrv
make daytimetcpcli


4. Run localy
-------------
- Open terminal and run:
sudo ./daytimetcpsrv
- Open the other terminal and run:
./daytimetcpcli 127.0.0.1

You should see something like:
num of bytes recved: 26
message received: Thu Dec 26 18:05:58 2013

 