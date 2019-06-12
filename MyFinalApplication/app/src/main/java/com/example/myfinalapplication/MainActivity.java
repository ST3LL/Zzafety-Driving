package com.example.myfinalapplication;

import android.app.PendingIntent;
import android.content.Intent;
import android.graphics.drawable.AnimationDrawable;
import android.support.constraint.ConstraintLayout;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;


public class MainActivity extends AppCompatActivity {

    private long backPressedTime;
    private Toast backToast;

    private Button button_main_1;
    private Button button_main_2;
    private Button button_main_3;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //background gradient main page
        ConstraintLayout constraintLayout = findViewById(R.id.layout);
        AnimationDrawable animationDrawable = (AnimationDrawable) constraintLayout.getBackground();
        animationDrawable.setEnterFadeDuration(2000);
        animationDrawable.setExitFadeDuration(4000);
        animationDrawable.start();


        //définition des boutons
        button_main_1 = (Button) findViewById(R.id.button_main_1); //dérive de tous les widgets
        button_main_1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                openletsgo();
            }
        });
        button_main_2 = (Button) findViewById(R.id.button_main_2);
        button_main_2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                openhowthatwork();
            }
        });
        button_main_3 = (Button) findViewById(R.id.button_main_3);
        button_main_3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                openaboutus();
            }
        });




    }
    public void openletsgo() {
        Intent intent = new Intent(this, letsgo.class);
        startActivity(intent);
    }
    public void openhowthatwork() {
        Intent intent = new Intent(this, howthatwork.class);
        startActivity(intent);
    }
    public void openaboutus() {
        Intent intent = new Intent(this, aboutus.class);
        startActivity(intent);
    }

}
