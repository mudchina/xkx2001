//Cracked by Roath

// mudlib: basis
// date:   1992/09/05

//#include <config.h>

int file_exists(string file)
{
	return (file_size(file) >= 0);
}

int directory_exists(string dirname)
{
	return (file_size(dirname) == -2);
}

/* user_exists.c
 * Written by Huthar@Portals
 *
 * This will return TRUE if the user exists, FALSE if no user exists
 */

/*int user_exists(string user)
{
   string file;

    file = PDATA_DIR + user[0..0] + "/" + user + __SAVE_EXTENSION__;

   if(!user) return 0;
   if(file_size(file) > 0)
        return 1;
   return 0;
}
*/
