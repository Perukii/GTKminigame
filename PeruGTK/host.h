

class peruHost{

public:
     GtkWidget * window;
     GtkWidget * canvas;

     int w=100, h=100, minw=0, minh=0;

     bool titlebar = true;

     peruHost(){

     }

     void setDefaultSize(int _w, int _h){
          w = _w;
          h = _h;
          gtk_window_set_default_size((GtkWindow *)window, w, h);
     }

     void setCurrentSize(int _w, int _h){
          w = _w;
          h = _h;
          gtk_window_resize((GtkWindow *)window, w, h);
     }

     void setMinimizeSize(int _minw, int _minh){
          minw = _minw;
          minh = _minh;
     }

     void setup(const char * cssfile = ""){
          window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
          canvas = gtk_drawing_area_new();
          gtk_widget_set_app_paintable(canvas, TRUE);
          gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
          g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);

          if(cssfile!="")peruCssProvide(cssfile);

          gtk_container_add(GTK_CONTAINER(window), canvas);
     }

     void run(){
          gtk_window_set_decorated(GTK_WINDOW(window),titlebar);
          gtk_window_set_default_size(GTK_WINDOW(window),w,h);
          gtk_widget_set_size_request(window,minw,minh);
          gtk_widget_show_all(window);
          gtk_main();
     }

};
