package tabian.com.datepickerdialog;

import android.provider.BaseColumns;

import static java.security.AccessController.getContext;

public final class FeedReaderContract {
    // To prevent someone from accidentally instantiating the contract class,
    // make the constructor private.
    private FeedReaderContract() {}

    /* Inner class that defines the table contents */
    public static class FeedEntry implements BaseColumns {
        public static final String TABLE_NAME = "event";
        public static final String COLUMN_NAME1 = "nazwa";
        public static final String COLUMN_NAME2 = "typZadania";
        public static final String COLUMN_NAME3 = "priorytet";
        public static final String COLUMN_NAME4 = "powiadomienie";
        public static final String COLUMN_NAME5 = "poczatek_wydarzenia";
        public static final String COLUMN_NAME6 = "koniec_wydarzenia";
        public static final String COLUMN_NAME7 = "adres";
        //public static final String COLUMN_NAME_SUBTITLE = "subtitle";
    }


}

