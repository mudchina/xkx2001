//Cracked by Roath
//  mudlib:  Basis
//  file:    save.c
//  author:  Truilkan
//  created: 1992/09/24

//  modified to run on tmi-2 by Truilkan (1992/11/09)

//#include <config.h>

#include "/inherit/save/data.c"
#include "/inherit/save/existence.c"

private static int persistent;

// set_persistent only callable by this_object() (including inheritors)

static void
set_persistent(int which)
{
   persistent = which;
}

void
save_data()
{
    string base;

    base = data_dir(this_object());
    if (!directory_exists(base)) {
        MASTER_OB->make_data_dir();
    }
   // I think this is never called...Leto
    save_object(data_file(this_object()));
}

int
restore_data()
{
   string file;

   file = data_file(this_object());
   if (file_exists(file + __SAVE_EXTENSION__)) {
      return restore_object(data_file(this_object()));
   } else {
      return 0;
   }
}

void
remove()
{
   if (persistent) {
      save_data();
   }
   destruct(this_object());
}

void
create()
{
   // restore won't have any effect unless savefile exists
   restore_data();
}
