package com.example.student.lab3;

import android.content.Intent;
import android.graphics.drawable.Drawable;
import android.os.Bundle;
import android.provider.MediaStore;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import java.util.Random;

public class MainActivity extends AppCompatActivity {

    static final int akcja = 0;
    static final int REQUEST_IMAGE_CAPTURE = 1;
    TextView e;
    ImageView img;
    Button btn;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        FloatingActionButton fab = (FloatingActionButton) findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Snackbar.make(view, "Replace with your own action", Snackbar.LENGTH_LONG)
                        .setAction("Action", null).show();

                Toast.makeText(getApplicationContext(),
                        "Kliknieto przycisk FAB",
                        Toast.LENGTH_SHORT).show();
            }
        });

        Intent intencja = new Intent(this, LoginActivity.class);
        startActivity(intencja);


    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        Toast.makeText(getApplicationContext(),
                "Kliknieto przycisk FAB",
                Toast.LENGTH_SHORT).show();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            Toast.makeText(getApplicationContext(),
                    "Kliknieto przycisk FAB",
                    Toast.LENGTH_SHORT).show();
            return true;
        }

        return super.onOptionsItemSelected(item);
    }

    public void kliknij(View obiekt){
        Toast.makeText(getApplicationContext(),
                "Kliknieto przycisk Button",
                Toast.LENGTH_SHORT).show();

        //Intent intencja2 = new Intent(MediaStore.ACTION_IMAGE_CAPTURE);
        //startActivityForResult(intencja2, REQUEST_IMAGE_CAPTURE);

        Random rand = new Random();
        int n = rand.nextInt(3) + 1;

        String tekst;
        tekst = Integer.toString(n);

        e = (TextView) findViewById (R.id.hello);
        e.setText(tekst);



        Button b = findViewById(R.id.button1);

        //b.setCompoundDrawablesWithIntrinsicBounds(getResources().getDrawable(android.R.drawable.arrow_down_float,getTheme()), 0, 0, 0);
        //17301583
        if(n==1){
            //getResources().getDrawable(android.R.drawable.arrow_down_float,getTheme());
            b.setBackgroundResource(android.R.drawable.arrow_down_float);
        }
        if(n==2){
            //getResources().getDrawable(android.R.drawable.btn_star,getTheme());
            b.setBackgroundResource(android.R.drawable.btn_star);
        }
        if(n==3){
            //getResources().getDrawable(android.R.drawable.ic_media_play,getTheme());
            b.setBackgroundResource(android.R.drawable.ic_media_play);
        }


    }

    public void klik(View obiekt){
        getResources().getDrawable(android.R.drawable.arrow_down_float,getTheme());
    }

}
