package com.example.student.sqliteapp;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

public class DatabaseHelper extends SQLiteOpenHelper {
    public static final String DATABASE_NAME = "Kalendarz.db";
    public static final String TABLE_NAME = "kalendarz_table";
    public static final String COL_1 = "id";
    public static final String COL_2 = "nazwa";
    public static final String COL_3 = "typZadania";
    public static final String COL_4 = "priorytet";
    public static final String COL_5 = "powiadomienie";
    public static final String COL_6 = "poczatek_wydarzenia";
    public static final String COL_7 = "koniec_wydarzenia";
    public static final String COL_8 = "adres";
    public static final String COL_9 = "notatka";

    public DatabaseHelper(Context context) {
        super(context, DATABASE_NAME, null, 1);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        db.execSQL("create table " + TABLE_NAME +" (id INTEGER PRIMARY KEY AUTOINCREMENT,nazwa TEXT,typZadania TEXT,priorytet INTEGER,powiadomienie TEXT,poczatek_wydarzenia DATE,koniec_wydarzenia DATE,adres TEXT,notatka TEXT)");
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        db.execSQL("DROP TABLE IF EXISTS "+TABLE_NAME);
        onCreate(db);
    }

    public boolean insertData(String nazwa,String typZadania,String priorytet,String powiadomienie,String poczatek_wydarzenia,String koniec_wydarzenia,String adres,String notatka) {
        SQLiteDatabase db = this.getWritableDatabase();
        ContentValues contentValues = new ContentValues();
        contentValues.put(COL_2,nazwa);
        contentValues.put(COL_3,typZadania);
        contentValues.put(COL_4,priorytet);
        contentValues.put(COL_5,powiadomienie);
        contentValues.put(COL_6,poczatek_wydarzenia);
        contentValues.put(COL_7,koniec_wydarzenia);
        contentValues.put(COL_8,adres);
        contentValues.put(COL_9,notatka);
        long result = db.insert(TABLE_NAME,null ,contentValues);
        if(result == -1)
            return false;
        else
            return true;
    }

    public Cursor getAllData() {
        SQLiteDatabase db = this.getWritableDatabase();
        Cursor res = db.rawQuery("select * from "+TABLE_NAME,null);
        return res;
    }

    public boolean updateData(String id,String nazwa,String typZadania,String priorytet,String powiadomienie,String poczatek_wydarzenia,String koniec_wydarzenia,String adres,String notatka) {
        SQLiteDatabase db = this.getWritableDatabase();
        ContentValues contentValues = new ContentValues();
        contentValues.put(COL_1,id);
        contentValues.put(COL_2,nazwa);
        contentValues.put(COL_3,typZadania);
        contentValues.put(COL_4,priorytet);
        contentValues.put(COL_5,powiadomienie);
        contentValues.put(COL_6,poczatek_wydarzenia);
        contentValues.put(COL_7,koniec_wydarzenia);
        contentValues.put(COL_8,adres);
        contentValues.put(COL_9,notatka);
        db.update(TABLE_NAME, contentValues, "ID = ?",new String[] { id });
        return true;
    }

    public Integer deleteData (String id) {
        SQLiteDatabase db = this.getWritableDatabase();
        return db.delete(TABLE_NAME, "ID = ?",new String[] {id});
    }
}