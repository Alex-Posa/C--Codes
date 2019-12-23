#include <gtk/gtk.h>
#include <stdlib.h>

typedef struct {
    GtkWidget* window;
    GtkWidget* layout;
    GtkWidget* tree_img;
    GtkWidget* kugel_eventbox;
    GtkWidget* kugel_img;
    GtkWidget* score_label;
    int width;
    int height;
    int bonus_score;
    int malus_score;
} GuiModel;

static void on_destroy(GtkWidget *src, gpointer data) {
    gtk_main_quit();
}

static int move_kugel(gpointer data) {
    GuiModel* m = (GuiModel*)data;
    m->malus_score += 10;
    gtk_fixed_move(GTK_FIXED(m->layout), m->kugel_eventbox, rand()%m->width, rand()%m->height);
    char buf[1024];
    sprintf(buf, "<span size=\"xx-large\">Score: %d</span>", m->bonus_score - m->malus_score);
    gtk_label_set_markup(GTK_LABEL(m->score_label), buf);
}

static gboolean on_click(GtkWidget* src, GdkEventButton* btn, gpointer data) {
    GuiModel* m = (GuiModel*)data;
    m->bonus_score += 100;
    printf("Score: %d\n", m->bonus_score - m->malus_score);
}

GtkWidget* get_scaled_image(char* name, int width, int height) {
    GdkPixbuf *buf = gdk_pixbuf_new_from_file(name, NULL);
    buf = gdk_pixbuf_scale_simple(buf, width, height, GDK_INTERP_NEAREST);
    return gtk_image_new_from_pixbuf(buf);
}

int main(int argc, char* argv[]) {
    gtk_init(&argc, &argv);
    srand(12345);

    GuiModel m;
    m.bonus_score = 0;
    m.malus_score = 0;

    m.window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_fullscreen(GTK_WINDOW(m.window));

    m.layout = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(m.window), m.layout);

    GdkScreen *screen = gtk_window_get_screen(GTK_WINDOW(m.window));
    GdkRectangle geo;
    GdkDisplay *display = gdk_screen_get_display(screen);
    GdkMonitor *monitor = gdk_display_get_primary_monitor(display);
    gdk_monitor_get_geometry(monitor, &geo);
    printf("Width: %d, Height: %d\n", geo.width, geo.height);
    m.width = geo.width;
    m.height = geo.height;

    m.tree_img = get_scaled_image("./tree.svg", m.width, m.height);
    gtk_fixed_put(GTK_FIXED(m.layout), m.tree_img, 0, 0);

    m.kugel_img = get_scaled_image("./kugel.png", m.width/20, m.width/18);
    m.kugel_eventbox = gtk_event_box_new();
    gtk_container_add(GTK_CONTAINER(m.kugel_eventbox), m.kugel_img);
    gtk_fixed_put(GTK_FIXED(m.layout), m.kugel_eventbox, 400, 400);

    m.score_label = gtk_label_new("");
    gtk_label_set_markup(GTK_LABEL(m.score_label), "<span size=\"xx-large\">Score:</span>");
    gtk_fixed_put(GTK_FIXED(m.layout), m.score_label, m.width-200, 50);

    gdk_threads_add_timeout(1000, move_kugel, &m);
    g_signal_connect(m.window, "destroy", G_CALLBACK(on_destroy), NULL);
    g_signal_connect(G_OBJECT(m.kugel_eventbox), "button_press_event", G_CALLBACK(on_click), &m);

    gtk_widget_show_all(m.window);

    gtk_main();
    return 0;
}
