{
    "targets": [{
        "target_name": "rectangle_highlight",
        "sources": [
            "src/main.cc",
            "src/draw/draw.cc",
            "src/skew_fix/skew_fix.cc",
            "src/fix_rotate/fix_rotate.cc"
        ],
        'conditions': [
      ['OS=="linux"', {
    'include_dirs': [
            "/usr/local/include/opencv4/"
    ],
    'libraries': ["/usr/local/lib/libopencv_core.so","/usr/local/lib/libopencv_calib3d.so","/usr/local/lib/libopencv_dnn.so","/usr/local/lib/libopencv_features2d.so","/usr/local/lib/libopencv_flann.so","/usr/local/lib/libopencv_gapi.so","/usr/local/lib/libopencv_highgui.so", "/usr/local/lib/libopencv_imgcodecs.so", "/usr/local/lib/libopencv_imgproc.so","/usr/local/lib/libopencv_ml.so","/usr/local/lib/libopencv_objdetect.so", "/usr/local/lib/libopencv_photo.so", "/usr/local/lib/libopencv_stitching.so", "/usr/local/lib/libopencv_videoio.so","/usr/local/lib/libopencv_video.so"],
      }],
      ['OS=="win"', {
          'include_dirs': [
            "<!(node env_windows_include.js)"
        ],
        'libraries': ["ws2_32.lib","<!(node env_windows_lib.js)"],
           "copies": [
            {
              "destination": "<(module_root_dir)/build/Release",
              "files": ["<!(node env_windows_dll.js)"]
            }
          ]
      }]],
        'configurations': {
            'Debug': {
                'msvs_settings': {
                            'VCCLCompilerTool': {
                                'RuntimeLibrary': '3' # /MDd
                    },
                },
            },
            'Release': {
                'msvs_settings': {
                            'VCCLCompilerTool': {
                                'RuntimeLibrary': '2' # /MD
                    },
                },
            },
        },
        'include_dirs': [
            "<!@(node -p \"require('node-addon-api').include\")"
        ],
        
        'dependencies': [
            "<!(node -p \"require('node-addon-api').gyp\")"
        ],
        'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ]
    }],
     
}