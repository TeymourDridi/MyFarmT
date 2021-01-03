#include <gtk/gtk.h>


void
on_buttonVAjout_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonRAjout_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonCherchModif_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonVmodif2_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonRModif_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonVModif_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonVSupp_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonRSupp_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonCherchSupp_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_button7_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button8_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonCherchAffiche_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button13_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button12_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button11_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_comboboxentryJour_button_press_event
                                        (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

void
on_buttonModif1_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonVmodif1_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_Homme_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Homme_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_GTK_TREE_VIEWChAffich_row_activated (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_TbuttonAffichtous_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_Homme2_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_treeviewsupp_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_TbuttonAffichsupp_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_entryCin_icon_release               (GtkEntry        *entry,
                                        GtkEntryIconPosition  arg1,
                                        GdkEvent        *event,
                                        gpointer         user_data);

void
on_entryCin_editing_done               (GtkCellEditable *celleditable,
                                        gpointer         user_data);

void
on_entryCin_changed                    (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_entryMail_changed                   (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_TbuttonAfficheAnSech_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_TbuttonInitAjout_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_calendarAjout_day_selected          (GtkCalendar     *calendar,
                                        gpointer         user_data);

void
on_buttonModif2_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_TbuttonInitModif_clicked            (GtkButton       *button,
                                        gpointer         user_data);


gboolean
on_GTK_TREE_VIEWChAffich_drag_drop     (GtkWidget       *widget,
                                        GdkDragContext  *drag_context,
                                        gint             x,
                                        gint             y,
                                        guint            time,
                                        gpointer         user_data);

void
on_GTK_TREE_VIEWChAffich_drag_end      (GtkWidget       *widget,
                                        GdkDragContext  *drag_context,
                                        gpointer         user_data);

gboolean
on_GTK_TREE_VIEWChAffich_select_all    (GtkTreeView     *treeview,
                                        gpointer         user_data);
/*
void
on_TbuttonAfficheAnSech_clicked        (GtkButton       *button,
                                        gpointer         user_data);*/

void
on_anplussech1_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonRetourAn_clicked              (GtkButton       *button,
                                        gpointer         user_data);
