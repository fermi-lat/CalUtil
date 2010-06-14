# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/CalUtil/SConscript,v 1.11 2010/06/12 17:20:50 jrb Exp $
# Authors: 
# Version: CalUtil-03-14-04
Import('baseEnv')
Import('listFiles')
Import('packages')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('addLinkDeps', package='CalUtil', toBuild='shared')

CalUtil = libEnv.SharedLibrary('CalUtil',
                               listFiles(['src/*.cxx',
                                          'src/SimpleCalCalib/*.cxx']))

progEnv.Tool('CalUtilLib')
progEnv.AppendUnique(CPPDEFINES = ['PACKAGE_NAME=\\"CalUtil\\"'])

test_CalUtil = progEnv.Program('test_CalUtil',
                               ['src/test/test_CalUtil.cxx'])

progEnv.Tool('registerTargets', package = 'CalUtil',
             libraryCxts = [[CalUtil, libEnv]],
             testAppCxts = [[test_CalUtil, progEnv]], 
             includes = listFiles(['CalUtil/*'], recursive = 1),
             xml = ['xml/idealCalib_flight.xml', 'xml/idealCalib_muon.xml'])




