package com.example.student.sqliteapp;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

import android.app.AlertDialog;
import android.database.Cursor;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;


public class MainActivity extends AppCompatActivity {
    DatabaseHelper myDb;
    EditText editNazwa,editTypZadania,editPriorytet,editPowiadomienie,editPoczatekWydarzenia,editKoniecWydarzenia,editAdres,editNotatka;
    Button btnAddData;
    Button btnviewAll;
    Button btnDelete;

    Button btnviewUpdate;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        myDb = new DatabaseHelper(this);

        editNazwa = (EditText)findViewById(R.id.editText_nazwa);
        editTypZadania = (EditText)findViewById(R.id.editText_typZadania);
        editPriorytet = (EditText)findViewById(R.id.editText_priorytet);
        editPowiadomienie = (EditText)findViewById(R.id.editText_powiadomienie);
        editPoczatekWydarzenia = (EditText)findViewById(R.id.editText_poczatek_wydarzenia);
        editKoniecWydarzenia = (EditText)findViewById(R.id.editText_priorytet);
        editAdres = (EditText)findViewById(R.id.editText_adres);
        editNotatka = (EditText)findViewById(R.id.editText_notatka);

        btnAddData = (Button)findViewById(R.id.button_add);
        btnviewAll = (Button)findViewById(R.id.button_viewAll);
        AddData();
        viewAll();
    }

    public  void AddData() {
        btnAddData.setOnClickListener(
                new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        boolean isInserted = myDb.insertData(editNazwa.getText().toString(),
                                editTypZadania.getText().toString(),
                                editPriorytet.getText().toString(),
                                editPowiadomienie.getText().toString(),
                                editPoczatekWydarzenia.getText().toString(),
                                editKoniecWydarzenia.getText().toString(),
                                editAdres.getText().toString(),
                                editNotatka.getText().toString() );
                        if(isInserted == true)
                            Toast.makeText(MainActivity.this,"Data Inserted",Toast.LENGTH_LONG).show();
                        else
                            Toast.makeText(MainActivity.this,"Data not Inserted",Toast.LENGTH_LONG).show();
                    }
                }
        );
    }

    public void viewAll() {
        btnviewAll.setOnClickListener(
                new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        Cursor res = myDb.getAllData();
                        if(res.getCount() == 0) {
                            // show message
                            showMessage("Error","Nothing found");
                            return;
                        }

                        StringBuffer buffer = new StringBuffer();
                        while (res.moveToNext()) {
                            buffer.append("Id:"+ res.getString(0)+"\n");
                            buffer.append("Nazwa:"+ res.getString(1)+"\n");
                            buffer.append("Typ zadania:"+ res.getString(2)+"\n");
                            buffer.append("Priorytet:"+ res.getString(3)+"\n");
                            buffer.append("Powiadomienie:"+ res.getString(4)+"\n");
                            buffer.append("Poczatek:"+ res.getString(5)+"\n");
                            buffer.append("Koniec:"+ res.getString(6)+"\n");
                            buffer.append("Adres:"+ res.getString(7)+"\n");
                            buffer.append("Notatka:"+ res.getString(8)+"\n\n");
                        }

                        // Show all data
                        showMessage("Data",buffer.toString());
                    }
                }
        );
    }

    public void showMessage(String title,String Message){
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setCancelable(true);
        builder.setTitle(title);
        builder.setMessage(Message);
        builder.show();
    }

}