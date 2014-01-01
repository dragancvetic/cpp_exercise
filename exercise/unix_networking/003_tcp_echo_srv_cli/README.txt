Chapter 5.

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
make tcpcli01
make tcpcli04
make tcpserv01
make tcpserv02
make tcpserv03
make tcpserv04

**********************************************************
4. Run localy
**********************************************************
a) Echo server/client
	i. Open terminal and run:
	./tcpserv01

	ii. Open the other three tabs terminal and run:
	./tcpcli01 127.0.0.1

	iii. You should see on the server side:
	connection from 127.0.0.1, port 42816
	connection from 127.0.0.1, port 42817
	connection from 127.0.0.1, port 42818

	iv. type text and press <enter>, text should be echoed

	v. Open new tab and do:
$ netstat -a |grep 9877
Active Internet connections (servers and established)
Proto Recv-Q Send-Q Local Address           Foreign Address         State      
tcp        0      0 *:9877                  *:*                     LISTEN     
tcp        0      0 localhost:9877          localhost:42816         ESTABLISHED
tcp        0      0 localhost:42816         localhost:9877          ESTABLISHED
tcp        0      0 localhost:9877          localhost:42817         ESTABLISHED
tcp        0      0 localhost:42818         localhost:9877          ESTABLISHED
tcp        0      0 localhost:42817         localhost:9877          ESTABLISHED
tcp        0      0 localhost:9877          localhost:42818         ESTABLISHED

$ ps -eo pid,tid,ppid,class,rtprio,ni,pri,psr,pcpu,stat,wchan:25,comm |grep tcp
  PID   TID  PPID CLS RTPRIO  NI PRI PSR %CPU STAT WCHAN                     COMMAND
 4183  4183  3300 TS       -   0  19   0  0.0 S+   inet_csk_wait_for_connect tcpserv01
 4186  4186  4115 TS       -   0  19   1  0.0 S+   n_tty_read                tcpcli01
 4187  4187  4183 TS       -   0  19   1  0.0 S+   sk_wait_data              tcpserv01
 4254  4254  4188 TS       -   0  19   1  0.0 S+   n_tty_read                tcpcli01
 4255  4255  4183 TS       -   0  19   1  0.0 S+   sk_wait_data              tcpserv01
 4323  4323  4257 TS       -   0  19   1  0.0 S+   n_tty_read                tcpcli01
 4324  4324  4183 TS       -   0  19   1  0.0 S+   sk_wait_data              tcpserv01

	vi. Close clients with <CTRL>-<D>, and do:
$ ps -eo pid,tid,ppid,class,rtprio,ni,pri,psr,pcpu,stat,wchan:25,comm |grep tcp
  PID   TID  PPID CLS RTPRIO  NI PRI PSR %CPU STAT WCHAN                     COMMAND
 4183  4183  3300 TS       -   0  19   0  0.0 S+   inet_csk_wait_for_connect tcpserv01
 4187  4187  4183 TS       -   0  19   0  0.0 Z+   exit                      tcpserv01 <defunct>
 4255  4255  4183 TS       -   0  19   1  0.0 Z+   exit                      tcpserv01 <defunct>
 4324  4324  4183 TS       -   0  19   1  0.0 Z+   exit                      tcpserv01 <defunct>

Important!!! The child processes are not removed fully, they are left in zomby state.

**********************************************************
a) Echo server/client connects 5 instancies
	i. Open terminal and run:
	./tcpserv03

	ii. Open the other three tabs terminal and run:
	./tcpcli04 127.0.0.1

	iii. You should see on the server side:
connection from 127.0.0.1, port 42846
connection from 127.0.0.1, port 42847
connection from 127.0.0.1, port 42848
connection from 127.0.0.1, port 42849
connection from 127.0.0.1, port 42850

	iv. Open new tab and do:
$ netstat -a |grep 9877
Active Internet connections (servers and established)
Proto Recv-Q Send-Q Local Address           Foreign Address         State      
tcp        0      0 *:9877                  *:*                     LISTEN     
tcp        0      0 localhost:42855         localhost:9877          ESTABLISHED
tcp        0      0 localhost:42857         localhost:9877          ESTABLISHED
tcp        0      0 localhost:9877          localhost:42859         ESTABLISHED
tcp        0      0 localhost:9877          localhost:42856         ESTABLISHED
tcp        0      0 localhost:42859         localhost:9877          ESTABLISHED
tcp        0      0 localhost:9877          localhost:42855         ESTABLISHED
tcp        0      0 localhost:9877          localhost:42857         ESTABLISHED
tcp        0      0 localhost:9877          localhost:42858         ESTABLISHED
tcp        0      0 localhost:42858         localhost:9877          ESTABLISHED
tcp        0      0 localhost:42856         localhost:9877          ESTABLISHED

$ ps -eo pid,tid,ppid,class,rtprio,ni,pri,psr,pcpu,stat,wchan:25,comm |grep tcp
  PID   TID  PPID CLS RTPRIO  NI PRI PSR %CPU STAT WCHAN                     COMMAND
 4651  4651  3300 TS       -   0  19   1  0.0 S+   inet_csk_wait_for_connect tcpserv04
 4652  4652  4115 TS       -   0  19   1  0.0 S+   n_tty_read                tcpcli04
 4653  4653  4651 TS       -   0  19   1  0.0 S+   sk_wait_data              tcpserv04
 4654  4654  4651 TS       -   0  19   0  0.0 S+   sk_wait_data              tcpserv04
 4655  4655  4651 TS       -   0  19   0  0.0 S+   sk_wait_data              tcpserv04
 4656  4656  4651 TS       -   0  19   0  0.0 S+   sk_wait_data              tcpserv04
 4657  4657  4651 TS       -   0  19   0  0.0 S+   sk_wait_data              tcpserv04

	v. close client <CTRL-D>, you should see on the server side:
connection from 127.0.0.1, port 42855
connection from 127.0.0.1, port 42856
connection from 127.0.0.1, port 42857
connection from 127.0.0.1, port 42858
connection from 127.0.0.1, port 42859
child 4653 terminated
child 4654 terminated
child 4655 terminated
child 4656 terminated
child 4657 terminated
	
	vi. check process statuses:
$ ps -eo pid,tid,ppid,class,rtprio,ni,pri,psr,pcpu,stat,wchan:25,comm |grep tcp
  PID   TID  PPID CLS RTPRIO  NI PRI PSR %CPU STAT WCHAN                     COMMAND
 4651  4651  3300 TS       -   0  19   0  0.0 S+   inet_csk_wait_for_connect tcpserv04
 
 Note: no zombi processes!!
 
Active Internet connections (servers and established)
Proto Recv-Q Send-Q Local Address           Foreign Address         State      
 4651  4651  3300 TS       -   0  19   0  0.0 S+   inet_csk_wait_for_connect tcpserv04
