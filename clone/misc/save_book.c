//Cracked by Roath

#include <ansi.h>
inherit ITEM;
inherit F_SAVE;

string query_book_name ();
object get_new_book ();
int save_book_sold (int book_no, int book_value);
void save_this_book(mapping book_content);
int pay_player_profit();
int check_book();
int remove_book (int book_no);

mapping *books;

int set_owner(string id)
{
        set("owner_id", id);
        return restore();
}

string query_save_file()
{
        string id;
        if( !stringp(id = query("owner_id")) ) return 0;
        return DATA_DIR + "book/" + id[0..0] + "/" + id;
}

void create()
{
       seteuid(getuid()); 
}

void save_this_book(mapping book_content) 
{
       if( !pointerp(books) )
       {
           books = ({ book_content });
       }
       else books += ({ book_content });
       save();
	   return;
}

int pay_player_profit()
{
	 int i, money_payed;

	 money_payed =0;
     if( !pointerp(books) )
         return notify_fail("你还未出版过一本书，就想要钱？\n");

	 for (i=0; i< sizeof(books); i++) {

         printf("【%s】至今一共卖出%d本，现还欠你%s\n", books[i]["title"],
		 books[i]["book_sold"],MONEY_D->price_str(books[i]["money_made"]));
		 money_payed += books[i]["money_made"];
		 // reset the money_made value
		 books[i]["money_made"] = 0;

	 }

	 // pay the player if he made any profit
	 if (money_payed > 0){
           printf("书贾取出%s，放在你的手里。\n", MONEY_D->price_str(money_payed));
           MONEY_D->pay_player(this_player(), money_payed);
	 }
	 // save the record
	 save();

	 return 1;
}

string query_book_name ()
{
       int i;

       i = random(sizeof(books));
       return sprintf( "%s/%d", books[i]["title"], i);

}

object get_new_book ()
{

     object book;
	 int i, new_price;

	
	 if( !books || sizeof(books) <1)
		 return book;
	 
	do
	 {
		i = random(sizeof(books));
	}while( !(books[i]) );
	
	 i=0;

	 book=new("/d/city/obj/newbook2");
     book->set("new_book",books[i]);
	 book->set_name(books[i]["title"], ({"book"}));
	 book->set("time_stamp",books[i]["publish_time"]);
	 book->set("book_number",i);
	 book->set("value",books[i]["current_price"]);

	 return book;
}

int save_book_sold (int book_no, int book_value)
{
	 books[book_no]["book_sold"]++;
	 books[book_no]["money_made"] += book_value;
	 // add 1 silver to the price for each book sold
	 books[book_no]["current_price"] += 100;
	 // if sold more than 50 copys, stamp the marker so it will never be
	 // discarded.
	 if (books[book_no]["book_sold"] > 50) {
			books[book_no]["keep_marker"] = 1;
	 }
	 save();
	 return 1;
}

// this is the function which checks all books and discard
// any old book that's not being sold
// every year we check all books one time and lower it's price

int check_book ()
{
	 int i, size;

	 i=0;
	 size=sizeof(books);
	 while (i<size) {
		books[i]["current_price"] -= 100;
		// if the book is worth less than 5 silver 
		// and it's not marked, kick it out
		if ((books[i]["current_price"] < 500) && (books[i]["keep_marker"] != 1)) {
			// once you remove a member of a array, the index changes
			// so push the index back 1 to re-align it
			remove_book(i);
			i--;
		}
		i++;
		size=sizeof(books);
	 }
	 save();
	 return 1;
}

// this is the function which checks all books and discard
// any old book that's not being sold
// every year we check all books one time and lower it's price

int discard_book (string arg)
{
	 int i, size;

	 i=0;
	 size=sizeof(books);
	 while (i<size) {
		 if( books[i]["title"] == arg )
		 {
			remove_book(i);
			i--;
		 }
		i++;
		size=sizeof(books);
	 }
	 save();
	 return 1;
}


int remove_book (int book_no)
{
   books -= ({ books[book_no] });
   return 1;
}

 
