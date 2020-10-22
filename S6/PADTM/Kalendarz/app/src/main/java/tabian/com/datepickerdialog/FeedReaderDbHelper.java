//no jazdy nieziemskie: https://developer.android.com/training/data-storage/sqlite.html#java

package tabian.com.datepickerdialog;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.provider.BaseColumns;

import java.security.AccessControlContext;
import java.util.ArrayList;
import java.util.List;

import static java.security.AccessController.getContext;
import static tabian.com.datepickerdialog.FeedReaderContract.*;

public class FeedReaderDbHelper extends SQLiteOpenHelper {
    public FeedReaderDbHelper(Context context, String name, SQLiteDatabase.CursorFactory factory, int version) {
        super(context, name, factory, version);
    }

    private static final String SQL_CREATE_ENTRIES =
            "CREATE TABLE " + FeedEntry.TABLE_NAME + " (" +
                    FeedEntry._ID + " INTEGER PRIMARY KEY," +
                    FeedEntry.COLUMN_NAME1 + " TEXT," +
                    FeedEntry.COLUMN_NAME2 + " TEXT," +
                    FeedEntry.COLUMN_NAME3 + " TEXT," +
                    FeedEntry.COLUMN_NAME4 + " TEXT," +
                    FeedEntry.COLUMN_NAME5 + " TEXT," +
                    FeedEntry.COLUMN_NAME6 + " TEXT," +
                    FeedEntry.COLUMN_NAME7 + " TEXT)";

    private static final String SQL_DELETE_ENTRIES =
            "DROP TABLE IF EXISTS " + FeedEntry.TABLE_NAME;

    // If you change the database schema, you must increment the database version.
    public static final int DATABASE_VERSION = 1;
    public static final String DATABASE_NAME = "FeedReader.db";

    public FeedReaderDbHelper(Context context) {
        super(context, DATABASE_NAME, null, DATABASE_VERSION);
    }
    public void onCreate(SQLiteDatabase db) {
        db.execSQL(SQL_CREATE_ENTRIES);
    }
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        // This database is only a cache for online data, so its upgrade policy is
        // to simply to discard the data and start over
        db.execSQL(SQL_DELETE_ENTRIES);
        onCreate(db);
    }
    public void onDowngrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        onUpgrade(db, oldVersion, newVersion);
    }

    FeedReaderDbHelper mDbHelper;
    //FeedReaderDbHelper mDbHelper = new FeedReaderDbHelper(getContext()); //NO NIE DZIALA TO

    public void putMethod() {
        // Gets the data repository in write mode
        SQLiteDatabase db2 = mDbHelper.getWritableDatabase();

        // Create a new map of values, where column names are the keys
        ContentValues values = new ContentValues();
        values.put(FeedEntry.COLUMN_NAME1, "todo");
        values.put(FeedEntry.COLUMN_NAME2, "todo2");

        // Insert the new row, returning the primary key value of the new row
        long newRowId = db2.insert(FeedEntry.TABLE_NAME, null, values);
    }

    SQLiteDatabase db = mDbHelper.getReadableDatabase();

    // Define a projection that specifies which columns from the database
// you will actually use after this query.
    String[] projection = {
            BaseColumns._ID,
            FeedEntry.COLUMN_NAME1,
            FeedEntry.COLUMN_NAME2
    };

    // Filter results WHERE "title" = 'My Title'
    String selection = FeedEntry.COLUMN_NAME1 + " = ?";
    String[] selectionArgs = { "My Title" };

    // How you want the results sorted in the resulting Cursor
    String sortOrder =
            FeedEntry.COLUMN_NAME2 + " DESC";

    public void cursorMethod() {
        Cursor cursor = db.query(
                FeedEntry.TABLE_NAME,   // The table to query
                projection,             // The array of columns to return (pass null to get all)
                selection,              // The columns for the WHERE clause
                selectionArgs,          // The values for the WHERE clause
                null,                   // don't group the rows
                null,                   // don't filter by row groups
                sortOrder               // The sort order
        );

        List itemIds = new ArrayList<>();
        while(cursor.moveToNext()) {
            long itemId = cursor.getLong(
                    cursor.getColumnIndexOrThrow(FeedEntry._ID));
            itemIds.add(itemId);
        }
        cursor.close();
    }


    // Define 'where' part of query.
    String selection2 = FeedEntry.COLUMN_NAME1 + " LIKE ?";
    // Specify arguments in placeholder order.
    String[] selectionArgs2 = { "MyTitle" };
    // Issue SQL statement.
    int deletedRows = db.delete(FeedEntry.TABLE_NAME, selection2, selectionArgs2);



    public void updateMethod() {
        SQLiteDatabase db = mDbHelper.getWritableDatabase();

        // New value for one column
        String title = "MyNewTitle";
        ContentValues values = new ContentValues();
        values.put(FeedEntry.COLUMN_NAME1, title);

        // Which row to update, based on the title
        String selection = FeedEntry.COLUMN_NAME1 + " LIKE ?";
        String[] selectionArgs = {"MyOldTitle"};

        int count = db.update(
                FeedEntry.TABLE_NAME,
                values,
                selection,
                selectionArgs);
    }

    protected void onDestroy() {
        mDbHelper.close();
        mDbHelper.onDestroy();
    }




}

