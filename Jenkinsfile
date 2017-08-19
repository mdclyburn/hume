def builders = [:]
def results = [:]

stage('Analysis') {
    node('master') {
	    checkout scm
    }
}

def platforms = [ 'freebsd', 'linux', 'mingw' ]
for (p in platforms) {
    def os = "Unknown (${p})"
	if (p == 'freebsd') {
	    os = 'FreeBSD'
    } else if (p == 'linux') {
	    os = 'Linux'
	} else if (p == 'mingw') {
	    os = 'Windows'
	}

    builders[platform] = {
	    node('master') {
            stage('Build') {
		    }
		}
    }
}

parallel builders
