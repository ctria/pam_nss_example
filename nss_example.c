#include <string.h>

#include <nss.h>
#include <pwd.h>

enum nss_status _nss_example_setpwent (void) {
  return NSS_STATUS_SUCCESS ;
}

enum nss_status _nss_example_endpwent (void) {
 return NSS_STATUS_SUCCESS ;
}

enum nss_status _nss_example_getpwent_r (struct passwd *result, char *buffer, size_t buflen, int *errnop) {
  static int i = 0 ;

  if( i++ == 0 ) {
    result->pw_name = "example_root";
    result->pw_passwd = "x";
    result->pw_uid = 0;
    result->pw_gid = 0;
    result->pw_dir = "/";
    result->pw_gecos = "A user added by example NSS module";
    result->pw_shell = "/bin/sh";
    return NSS_STATUS_SUCCESS ;  
  } else if (i++ == 2) {
    result->pw_name = "example_user";
    result->pw_passwd = "x";
    result->pw_uid = 100000;
    result->pw_gid = 0;
    result->pw_dir = "/";
    result->pw_gecos = "A user added by example NSS module";
    result->pw_shell = "/bin/sh";
    return NSS_STATUS_SUCCESS ;  
  } else {
    return NSS_STATUS_NOTFOUND ;
  }
} ;

enum nss_status _nss_example_getpwuid_r (uid_t uid, struct passwd *result, char *buffer, size_t buflen, int *errnop) {
  if (uid == 100000) {
    result->pw_name = "example_user";
    result->pw_passwd = "x";
    result->pw_uid = 100000;
    result->pw_gid = 0;
    result->pw_dir = "/";
    result->pw_gecos = "A user added by example NSS module";
    result->pw_shell = "/bin/sh";
    return NSS_STATUS_SUCCESS ;
  } else {
    return NSS_STATUS_NOTFOUND ;
  }
} ;

enum nss_status _nss_example_getpwnam_r (const char *nam, struct passwd *result, char *buffer, size_t buflen, int *errnop) {
  if (strcmp(nam, "example_root") == 0) {
    result->pw_name = "example_root";
    result->pw_passwd = "x";
    result->pw_uid = 0;
    result->pw_gid = 0;
    result->pw_dir = "/";
    result->pw_gecos = "A user added by example NSS module";
    result->pw_shell = "/bin/sh";
    return NSS_STATUS_SUCCESS ;
  } else if (strcmp(nam, "example_user") == 0) {
    result->pw_name = "example_user";
    result->pw_passwd = "x";
    result->pw_uid = 100000;
    result->pw_gid = 0;
    result->pw_dir = "/";
    result->pw_gecos = "A user added by example NSS module";
    result->pw_shell = "/bin/sh";
    return NSS_STATUS_SUCCESS ;  
  } else {
    return NSS_STATUS_NOTFOUND ;
  }

} ;