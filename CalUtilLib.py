#$Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/CalUtil/CalUtilLib.py,v 1.2 2008/09/25 21:46:27 ecephas Exp $
def generate(env, **kw):
    if not kw.get('depsOnly', 0):
        env.Tool('addLibrary', library = ['CalUtil'])
    env.Tool('identsLib')
    env.Tool('addLibrary', library = env['rootLibs'])
    env.Tool('xmlBaseLib')
def exists(env):
    return 1;
