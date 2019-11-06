package com.example.kotlin_1

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.EditText
import android.widget.Toast


class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        var editText = findViewById<EditText>(R.id.editText)
        editText.setHint("Your name?")

        var sendButton = findViewById<Button>(R.id.button)

        sendButton.setOnClickListener{
            Toast.makeText(this, "Welcome ${editText.text}!", Toast.LENGTH_LONG).show()
            editText.setText("")
        }
    }
}
