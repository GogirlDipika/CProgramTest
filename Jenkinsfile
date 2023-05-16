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
            }
        }
        stage('Read cppcheck.xml') {
            steps {
                script{
                // Read Cppcheck XML file into a string
                    def xmlString = readFile 'cppcheck.xml'

                    // Parse XML string using XmlSlurper
                    def xml = new XmlSlurper().parseText(xmlString)

                    // Access elements in the XML document
                    def errorCount = xml.@errors.toInteger()

                    // Print out results
                    echo "Cppcheck found ${errorCount} errors."
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
