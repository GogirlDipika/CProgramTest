pipeline {
    agent any
    
    stages {
        stage('checkout') {
            steps {
                checkout scmGit(branches: [[name: '*/main']], extensions: [], userRemoteConfigs: [[credentialsId: 'jenkinstoken', url: 'https://github.com/GogirlDipika/CProgramTest.git']])
            }
        }
        
        stage('clone') {
            steps {
                git branch: 'main', credentialsId: 'jenkinstoken', url: 'https://github.com/GogirlDipika/CProgramTest.git'
            }
        }
        stage('Cppcheck') {
            steps {
                bat 'cppcheck --platform=win64 --inconclusive --enable=all --xml-version=2 --xml cppcheck.xml'
		    
		// Publish the results using the CppcheckPublisher plugin
        	publishCppcheck pattern: 'cppcheck.xml', enabled: true, threshold: 4, ignoreBlankFiles: true
            }
        }
        stage('Quality gate') {
            steps {
			script{
				sleep 10
				import groovy.xml.XmlSlurper

				def xmlSlurper = new XmlSlurper()
				def xml = xmlSlurper.parse('cppcheck.xml')

				def errors = xml.errors
				def warnings = xml.warnings

				echo "The number of errors is ${errors.size()}"
				echo "The number of warnings is ${warnings.size()}"
				}
			}
		}
    }
    post {
        always {
            publishCppcheck pattern:'cppcheck.xml'
        }
    }
}
