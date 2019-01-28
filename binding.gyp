{
    "targets": [{
        "target_name": "rectangle_highlight",
        "cflags!": [ "-fno-exceptions" ],
        "cflags_cc!": [ "-fno-exceptions" ],
        "sources": [
            "src/main.cc",
            "src/draw/draw.cc",
        ],
        'conditions': [
      ['OS=="linux"', {

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