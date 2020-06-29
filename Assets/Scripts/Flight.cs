using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;
using System.Threading;
using UnityEditorInternal;

public class Flight : MonoBehaviour
{
    public float AmbientSpeed = 30.0f;

    public float RotationSpeed = 30.0f;
    
    Vector3 lastposition;

    public float distance;

    public float pitch;

    public float roll;

    private Rigidbody plane;

    public static SerialPort sp;

    public int pitch_state;

    public int roll_state;

    public int prev_pitch_state = 0;

    public int prev_roll_state = 0;

    // Use this for initialization
    void Start()
        
    {
        Debug.Log("Flight script added to:" + gameObject.name);
        plane = GetComponent<Rigidbody>();
        lastposition = transform.position;
        OpenConnection();



    }

    // Update is called once per frame
    void Update()
    {
        sp.ReadTimeout = 25;

        transform.position += transform.forward * Time.deltaTime * -1 * AmbientSpeed;

        Quaternion AddRot = Quaternion.identity;
        roll = 0;
        pitch = 0;

        roll = Input.GetAxis("Horizontal") * (Time.deltaTime * RotationSpeed); 
        pitch = Input.GetAxis("Vertical") * (Time.deltaTime * RotationSpeed); 
        AddRot.eulerAngles = new Vector3(pitch, roll);
        plane.rotation *= AddRot;
        // set pitch and roll angle

        transform.Rotate(pitch, 0.0f, roll);

        Vector3 AddPos = transform.position += transform.forward * Time.deltaTime * -1 * AmbientSpeed;
        AddPos = plane.rotation * AddPos;
        plane.velocity = AddPos * (Time.deltaTime * AmbientSpeed);
        // how the airplane moves

        distance += Vector3.Distance(transform.position, lastposition);

        float terraininstantheight = Terrain.activeTerrain.SampleHeight(transform.position);

        if (terraininstantheight > transform.position.y)
        {
            transform.position = new Vector3(transform.position.x,
                terraininstantheight, transform.position.z);
        }
        //plane doesn't go into the terrain

        lastposition = transform.position;
        lastposition.x = Mathf.RoundToInt(gameObject.transform.position.x);
        lastposition.y = Mathf.RoundToInt(gameObject.transform.position.y);
        lastposition.z = Mathf.RoundToInt(gameObject.transform.position.z);

        if (pitch > 0)
        {
            pitch_state = 1;
        }
        else if (pitch < 0)
        {
            pitch_state = -1;
        }
        else pitch_state = 0;

        if (roll > 0)
        {
            roll_state = 1;
        }
        else if (roll < 0)
        {
            roll_state = -1;
        }
        else roll_state = 0;

        if (pitch_state != prev_pitch_state || roll_state != prev_roll_state)
        {
            switch (pitch_state)
            {
                case 1:
                    if (roll > 0)
                    {
                        sp.Write("A");
                    }
                    else if (roll < 0)
                    {
                        sp.Write("B");
                    }
                    else sp.Write("C");
                    break;
                case -1:
                    if (roll > 0)
                    {
                        sp.Write("D");
                    }
                    else if (roll < 0)
                    {
                        sp.Write("E");
                    }
                    else sp.Write("F");
                    break;
                case 0:
                    if (roll > 0)
                    {
                        sp.Write("G");
                    }
                    else if (roll < 0)
                    {
                        sp.Write("H");
                    }
                    else sp.Write("I");
                    break;
            }
         prev_pitch_state = pitch_state;
         prev_roll_state = roll_state;
         Debug.Log("Done Sending");
        }   
    }

    public void OpenConnection()
    {
        sp = new SerialPort("COM3", 9600, Parity.None, 8, StopBits.One);
        Debug.Log("OpenConnection started");
        if (sp != null)
        {
            if (sp.IsOpen)
            {
                sp.Close();
                Debug.Log("Closing port, because it was already open!");
            }
            else
            {
                sp.Open();  // opens the connection
                            // sets the timeout value before reporting error
                Debug.Log("Port Opened!");
            }
        }
        else
        {
            if (sp.IsOpen)
            {
                print("Port is already open");
            }
            else
            {
                print("Port == null");
            }
        }
        Debug.Log("Open Connection finished running");
    }

    void OnApplicationQuit()
    {
        if (sp != null)
            sp.Close();
    }
}

