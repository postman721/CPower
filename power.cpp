/*++Power v.1 Copyright (c) 2017 JJ Posti <techtimejourney.net> 
This program comes with ABSOLUTELY NO WARRANTY; 
for details see: http://www.gnu.org/copyleft/gpl.html. 
This is free software, and you are welcome to redistribute it under 
GPL Version 2, June 1991")*/
#include <gtk/gtk.h>
#include <cstdlib>
using namespace std;
void button1_clicked(GtkWidget *button1)
{
	system("gksudo " "pm-suspend"); 
}

void button2_clicked(GtkWidget *button2)
{
	system("gksudo " "reboot"); 
}

void button3_clicked(GtkWidget *button3)
{
	system("gksudo " "poweroff"); 
}
//Main Function begins.
int main(int argc, char *argv[]) 
{
	GtkWidget *window; //Here we declare some pointers.
	GtkWidget *button1;
	GtkWidget *button2;
	GtkWidget *button3;
	GtkWidget *box1;
//Gtk_init
	gtk_init(&argc, &argv);
//Window definitions. 
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "++Power");
	gtk_widget_set_size_request(window, 300, 50);
	gtk_window_set_resizable (GTK_WINDOW(window), FALSE);	
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_container_set_border_width(GTK_CONTAINER(window), 3);
//Box + Buttons
	box1 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, TRUE);
    button1 = gtk_button_new_with_label("Suspend");
    button2 = gtk_button_new_with_label("Reboot");
    button3 = gtk_button_new_with_label("Power off");
    
//Connecting buttons to functions    
    g_signal_connect (button1, "clicked",
		      G_CALLBACK (button1_clicked),
		      button1); 

 g_signal_connect (button2, "clicked",
		      G_CALLBACK (button2_clicked),
		      button2);

 g_signal_connect (button3, "clicked",
		      G_CALLBACK (button3_clicked),
		      button3);
		      		      		      
//First we add our box to the gtk_container and then we pack our stuff inside the box.    
	gtk_container_add(GTK_CONTAINER(window), box1);
	gtk_box_pack_start(GTK_BOX(box1), button1, FALSE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(box1), button2, FALSE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(box1), button3, FALSE, TRUE, 0);
//Show the window.
	gtk_widget_show_all(window);
//Destroy the window callback. Window needs to get destroyed upon exit. Otherwise it might run forever and this is bad for the memory.  
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_main();
}
