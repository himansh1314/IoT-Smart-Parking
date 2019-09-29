package com.himanshmulchandani.smartparking;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AutoCompleteTextView;
import android.widget.Button;

public class Register extends AppCompatActivity {
    AutoCompleteTextView name,email,password,confirm;
    Button register;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_register);
        name = findViewById(R.id.name_text);
        email = findViewById(R.id.email_text);
        password = findViewById(R.id.password_text);
        confirm = findViewById(R.id.confirm_text);
        register = findViewById(R.id.register_button);
        register.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                registerUser();
            }
        });
    }

    private void registerUser() {
        String username = name.getText().toString();
        String emailID = email.getText().toString();
        String password1 = password.getText().toString();
        String confirmPassword = confirm.getText().toString();
        if(password.equals(password1)){

        }
    }
}
