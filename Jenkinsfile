pipeline {
	agent { node { label 'master' } }
	stages {
		stage('Analysis') {
			steps {
				sh 'uname -a'
				sh 'echo ha > a_file'
				sh 'ls'
			}
		}

		stage('Build (FreeBSD)') {
			agent { node { label 'freebsd' } }
			steps {
				sh 'rm -rf build; mkdir build; cd build; cmake ..; make clean; make; mv libhume.a ../libhume-freebsd.a'
				archiveArtifacts(artifacts: 'libhume-freebsd.a', fingerprint: true)
			}
		}

		stage('Build (Linux)') {
			agent { node { label 'linux' } }
			steps {
				sh 'rm -rf build; mkdir build; cd build; cmake ..; make; mv libhume.a ../libhume-linux.a'
				archiveArtifacts(artifacts: 'libhume-linux.a', fingerprint: true)
			}
		}

		stage('Build (MinGW)') {
			agent { node { label 'mingw' } }
			steps {
				sh 'rm -rf build; mkdir build; cd build; cmake -DCMAKE_TOOLCHAIN_FILE=../MinGW_toolchain.cmake ..; make; mv libhume.a ../libhume-mingw.a'
				archiveArtifacts(artifacts: 'libhume-mingw.a', fingerprint: true)
			}
		}
	}
}
