# Build LibQQt Tips  

1. 一般建议    
使用Qt Creator编译，  
或者使用PyMake提供环境从命令行编译，  
或者使用PyQMake、PyAutoMake等专用编译工具编译。    
2. 编译时间  
LibQQt的编译时间2分钟-2小时，请合理安排时间。  

# Environ and Building  

## Qt Creator   

1. Setting - Default building directory  
    - 这是建议配置，LibQQt工程组织代码，已经不再依赖编译目录。
    - [buildroot]/[projectname]/[kit.systemname]/[qtversion]/[buildtype]
    - 需要在Qt Creator的Qt Kit页面对每个Qt Kit设置kit system name。
2. Build Page
    - 每个目标设置环境变量，设置QSYS，
    - 针对QSYS的可取值，请查阅[LibQQt sourcecode]/multi-link/multi-link/add_platform.pri。  
    - 常用的几个环境，LibQQt会自动设置QSYS，用户观察一下是否准确即可。
    - 不准确的则自主设置。
3. LibQQt自主技术设置【多链】
    - 在电脑上，用户主目录/.qmake/app_configure.pri里设置，
    - APP_BUILD_ROOT=...，建议设置，但是LibQQt不依赖。
    - LIB_SDK_ROOT=...，必要设置，LibQQt发布SDK用，使用多链技术的Lib工程也用。真正发布到[LIB_SDK_ROOT]/QQt/[QSYS]/...
    - APP_DEPLOY_ROOT=...，必要设置，依赖LibQQt的，使用多链技术的App工程用。  
4. 开始编译
    - qmake ...
    - make ...

## PyMake提供环境和开启编译  

```json  

Separate 环境的设置：
    "path-assemblage": {
        "root.prod": "...",
        "root.sdk": "...",
        "root.build": "...",
        ...
    },
    "environ": {
        "<env-name>": {
            "path+": [
                "path/to/qmake"
                ...
            ],
            "QTDIR": "...",
            "QTVERSION": "...",
            "QTSPEC": "...",
            "QTCONFIG": "...",
            "QSYS": "...",
            "QKIT": "... [maybe] [Multi-link Technology v1]",
            "CMAKEGENERATOR": "...",
            "makex": "...",
            ...
        }
    }
    
```

1. 使用PyMake工具详细的配置每个Separate环境。  
1. LibQQt自主技术设置【多链】
    - 在电脑上，用户主目录/.qmake/app_configure.pri里设置，
    - APP_BUILD_ROOT=...，建议设置，但是LibQQt不依赖。
    - LIB_SDK_ROOT=...，必要设置，LibQQt发布SDK用，使用多链技术的Lib工程也用。真正发布到[LIB_SDK_ROOT]/QQt/[QSYS]/...
    - APP_DEPLOY_ROOT=...，必要设置，依赖LibQQt的，使用多链技术的App工程用。  
1. 开始编译
    - 切换到LibQQt源代码目录,  
    - pymake use <env-name> ccvp here build.qmake QQt

## 使用PyQMake-Gui编译  

1. PyQMake依赖PyMake配置的每个Separate环境。
1. PyQMake-Gui自动切换PyMake提供的环境，用户选取一个环境，点击环境名称，即可切换编译目标环境。
1. PyQMake-Gui自动设置LibQQt的自主技术【多链】。
1. 把 LibQQt 源代码目录的 QQt.pro 拖放到 PyQMake-Gui 窗口上。
2. 点击Start Building即可。  

## 使用PyAutoMake-Gui编译  

1. PyAutoMake依赖PyMake配置的每个Separate环境。
1. PyAutoMake-Gui自动切换PyMake提供的环境，用户选取一个环境，点击环境名称即可切换编译目标环境。
1. PyAutoMake-Gui自动设置LibQQt的自主技术【多链】，其他使用多链技术的qmake工程同样可用。
1. 把 LibQQt 源代码目录的 QQt.pro 拖放到 PyAutoMake-Gui 窗口上。
2. 开始编译  
    - 先点击configure，等待（qmake）完成，  
    - 再点击Start Building。  

