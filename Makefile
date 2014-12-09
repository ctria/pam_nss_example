all: libnss_example.so.2 pam_example.so

libnss_example.so.2:
	gcc -fPIC -shared -o libnss_example.so.2 -Wl,-soname,libnss_example.so.2 nss_example.c


pam_example.so:
	gcc -fPIC -shared -o pam_example.so pam_example.c


clean:
	rm -f pam_example.so libnss_example.so.2

