package tina.com.player;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.SurfaceView;
import android.view.View;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private SurfaceView surfaceView;
    private TinaPlayer player;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        surfaceView = findViewById(R.id.surfaceView);
        player = new TinaPlayer();
        player.setSurfaceView(surfaceView);
        player.setDataSource("rtmp://live.hkstv.hk.lxdns.com/live/hks");
        player.setOnPrepareListener(new TinaPlayer.OnPrepareListener() {
            @Override
            public void onPrepare() {
                runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        Toast.makeText(MainActivity.this, "可以开始播放了", Toast.LENGTH_SHORT).show();
                    }
                });
            }
        });

    }

    public void start(View view) {
        player.prepare();
    }
}
