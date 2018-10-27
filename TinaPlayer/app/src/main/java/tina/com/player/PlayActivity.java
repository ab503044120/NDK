package tina.com.player;

import android.app.Activity;
import android.content.res.Configuration;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.util.DisplayMetrics;
import android.view.SurfaceView;
import android.view.ViewGroup;
import android.view.WindowManager;
import android.widget.Toast;

import com.trello.rxlifecycle2.components.support.RxAppCompatActivity;

/**
 * @author Lance
 * @date 2018/9/7
 */
public class PlayActivity extends RxAppCompatActivity {
    private TinaPlayer dnPlayer;
    public String url;

    SurfaceView surfaceView;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON, WindowManager
                .LayoutParams.FLAG_KEEP_SCREEN_ON);
        setContentView(R.layout.activity_play);
        surfaceView = findViewById(R.id.surfaceView);
        dnPlayer = new TinaPlayer();
        dnPlayer.setSurfaceView(surfaceView);
        dnPlayer.setOnPrepareListener(new TinaPlayer.OnPrepareListener() {

            @Override
            public void onPrepare() {
                runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        Toast.makeText(PlayActivity.this, "开始播放", Toast.LENGTH_SHORT).show();
                    }
                });
                dnPlayer.start();
            }
        });

        url = getIntent().getStringExtra("url");
        dnPlayer.setDataSource(url);
    }

    @Override
    public void onConfigurationChanged(Configuration newConfig) {
        super.onConfigurationChanged(newConfig);
        DisplayMetrics dm = new DisplayMetrics();
        if (newConfig.orientation == Configuration.ORIENTATION_PORTRAIT) {
            getWindowManager().getDefaultDisplay().getMetrics(dm);
            int screenWidth = dm.widthPixels;
            ViewGroup.LayoutParams lp = surfaceView.getLayoutParams();
            lp.width = screenWidth;
            lp.height = screenWidth * 9/16;
            surfaceView.setLayoutParams(lp);

        } else if (this.getResources().getConfiguration().orientation == Configuration.ORIENTATION_LANDSCAPE) {
            //横屏显示
            ViewGroup.LayoutParams lp = surfaceView.getLayoutParams();
            lp.width = lp.MATCH_PARENT;
            lp.height = lp.MATCH_PARENT;
            surfaceView.setLayoutParams(lp);

        }

    }

    @Override
    protected void onResume() {
        super.onResume();
        dnPlayer.prepare();
    }

    @Override
    protected void onStop() {
        super.onStop();
        dnPlayer.stop();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        dnPlayer.release();
    }
}
