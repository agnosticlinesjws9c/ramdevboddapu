#---------------------------------------------------------------------------------
#app_base_manager.pri
#应用程序和Library的基础管理器，统一使用这个管理器。
#
#---------------------------------------------------------------------------------

################################################################################
#包含这个pri依赖的pri
################################################################################
include ($${PWD}/add_platform.pri)
include ($${PWD}/add_function.pri)

################################################################################
#多链接技术入口
################################################################################
include($${PWD}/add_multi_link_technology.pri)

################################################################################
#这里的pri提供multi link的全部函数
################################################################################
#app发布所需要的函数
include ($${PWD}/add_deploy.pri)

#app发布配置项需要的函数
include ($${PWD}/add_deploy_config.pri)

#app链接所需要的函数
include ($${PWD}/add_link.pri)

####################################################################################
#app base manager 都做了一下这些事情
####################################################################################
#发布app和libQQt
#注意，此处强制发布App 不需要用户手动调用。
#注意，此处强制依赖LibQQt，不需要用户手动发布LibQQt。
app_deploy()
app_deploy_lib(QQt)
#如果用户依赖了其他的lib，便可以用app_deploy_lib进行拷贝依赖到app发布区域。
#并且这个工作，后续持续收到app_deploy配置开关的控制。
#note: app_deploy 一个配置开关 一个函数 两个都有效使用
#注意，用户必须先发布lib 再发布app

#发布配置
#用户手动调用app_deploy_config(源配置文件所在位置)

#链接其他链接库
#在app_custom_manager.pri里进行
#调用app_link(libName)

